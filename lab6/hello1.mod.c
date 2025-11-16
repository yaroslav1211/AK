#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

KSYMTAB_FUNC(print_hello, "", "");

SYMBOL_CRC(print_hello, 0xd272d446, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xcb8b6ec6, "kfree" },
	{ 0xd272d446, "__x86_return_thunk" },
	{ 0xd272d446, "__fentry__" },
	{ 0xd710adbf, "__kmalloc_noprof" },
	{ 0xe8213e80, "_printk" },
	{ 0x97acb853, "ktime_get" },
	{ 0xd268ca91, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0xcb8b6ec6,
	0xd272d446,
	0xd272d446,
	0xd710adbf,
	0xe8213e80,
	0x97acb853,
	0xd268ca91,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"kfree\0"
	"__x86_return_thunk\0"
	"__fentry__\0"
	"__kmalloc_noprof\0"
	"_printk\0"
	"ktime_get\0"
	"module_layout\0"
;

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "70F83A8D7D309FA17C844FD");
