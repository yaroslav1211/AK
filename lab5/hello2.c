#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include "hello1.h"

MODULE_AUTHOR("Vodopyanov Yaroslav");
MODULE_DESCRIPTION("module2");
MODULE_LICENSE("Dual BSD/GPL");

static unsigned int count = 1;
module_param(count, uint, 0444);
MODULE_PARM_DESC(count, "Number of print hello");

static int __init hello2_init(void)
{
    int i;

    if (count == 0 || (count >= 5 && count <= 10))
        pr_warn("hello2: unusual count value = %u\n", count);
    else if (count > 10) {
        pr_err("hello2: count too large (%u)\n", count);
        return -EINVAL;
    }

    pr_info("hello2: calling print_hello() %u times...\n", count);

    for (i = 0; i < count; i++)
        print_hello();

    pr_info("hello2: done\n");
    return 0;
}

static void __exit hello2_exit(void)
{
    pr_info("hello2: module unloaded\n");
}

module_init(hello2_init);
module_exit(hello2_exit);
