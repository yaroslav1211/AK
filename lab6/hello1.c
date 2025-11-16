#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/slab.h>
#include <linux/list.h>
#include <linux/ktime.h>
#include <linux/atomic.h>
#include "hello1.h"

MODULE_AUTHOR("Vodopyanov Yaroslav");
MODULE_DESCRIPTION("module1");
MODULE_LICENSE("Dual BSD/GPL");

struct hello_entry {
    struct list_head list;
    ktime_t start_time;
    ktime_t end_time;
};

static LIST_HEAD(hello_list);
static atomic_t hello_calls = ATOMIC_INIT(0);

void print_hello(void)
{
    struct hello_entry *entry;
    int call = atomic_inc_return(&hello_calls);

    entry = kmalloc(sizeof(*entry), GFP_KERNEL);

    if (call == 3)
        entry = NULL;

    if (!entry) {
        pr_err("hello1: kmalloc returned NULL on %d\n", call);
        return;
    }

    entry->start_time = ktime_get();
    pr_info("hello1: Hello, world! (%d)\n", call);
    entry->end_time = ktime_get();

    list_add_tail(&entry->list, &hello_list);
}
EXPORT_SYMBOL(print_hello);

static int __init hello1_init(void)
{
    pr_info("hello1: loaded\n");
    return 0;
}

static void __exit hello1_exit(void)
{
    struct hello_entry *ptr, *tmp;
    pr_info("hello1: unloading\n");
    list_for_each_entry_safe(ptr, tmp, &hello_list, list) {
        s64 duration = ktime_to_ns(ktime_sub(ptr->end_time, ptr->start_time));
        pr_info("hello1: call duration %lld ns\n", duration);
        list_del(&ptr->list);
        kfree(ptr);
    }
    pr_info("hello1: unloaded\n");
}

module_init(hello1_init);
module_exit(hello1_exit);
