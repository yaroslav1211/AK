
/*
 * Copyright (c) 2017, GlobalLogic Ukraine LLC
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    This product includes software developed by the GlobalLogic.
 * 4. Neither the name of the GlobalLogic nor the
 *    names of its contributors may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY GLOBALLOGIC UKRAINE LLC ``AS IS`` AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL GLOBALLOGIC UKRAINE LLC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/slab.h>
#include <linux/list.h>
#include <linux/ktime.h>

MODULE_AUTHOR("Vodopyanov Yaroslav");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

static unsigned int count = 1;
module_param(count, uint, 0444);
MODULE_PARM_DESC(count, "Number of times to print 'Hello, world!'");

struct hello_entry {
	struct list_head list;
	ktime_t time;
};

static LIST_HEAD(hello_list);

static int __init hello_init(void)
{
	int i;
	struct hello_entry *entry;

	if (count == 0 || (count >= 5 && count <= 10)) {
        	pr_warn("Warning: unusual count value = %u\n", count);
   	} else if (count > 10) {
        	pr_err("Error: count too large (%u)\n", count);
        	return -EINVAL;
	}

	for (i = 0; i < count; i++) {
        	entry = kmalloc(sizeof(*entry), GFP_KERNEL);
        	if (!entry) {
            		pr_err("Memory allocation failed at iteration %d\n", i);
            		return -ENOMEM;
        	}

       		entry->time = ktime_get();
        	list_add_tail(&entry->list, &hello_list);
        	pr_info("Hello, world! (%d)\n", i + 1);
    	}

    	return 0;

}
static void __exit hello_exit(void)
{
	struct hello_entry *ptr, *tmp;
	list_for_each_entry_safe(ptr, tmp, &hello_list, list) {
        	pr_info("Time: %lld ns\n", ktime_to_ns(ptr->time));
        	list_del(&ptr->list);
        	kfree(ptr);
    	}
    	pr_info("Goodbye, world!\n");
}

module_init(hello_init);
module_exit(hello_exit);
