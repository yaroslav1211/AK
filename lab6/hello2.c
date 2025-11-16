#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include "hello1.h"

MODULE_AUTHOR("Vodopyanov Yaroslav");
MODULE_DESCRIPTION("module2");
MODULE_LICENSE("Dual BSD/GPL");

static unsigned int count = 1;
module_param(count, uint, 0444);
MODULE_PARM_DESC(count, "Number to print hello");




static int __init hello2_init(void)
{
    int i;

    if (count == 0 || (count >= 5 && count <= 10))
        pr_warn("hello2: unusual count value = %u\n", count);

    BUG_ON(count > 10);

    pr_info("hello2: print_hello %u \n", count);

    for (i = 0; i < count; i++)
        print_hello();

    pr_info("hello2: init complete\n");
    return 0;
}

static void __exit hello2_exit(void)
{
    pr_info("hello2: unloaded\n");
}

module_init(hello2_init);
module_exit(hello2_exit);
