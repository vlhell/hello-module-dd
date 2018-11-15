/* hello.c */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init hello_init(void)
{
    pr_alert("twas init and HELLO!\n");
    return 0;
}

static void __exit hello_exit(void)
{
    pr_alert("twas exit and GOODBYE!\n");
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Hello-world or greeting module");
MODULE_AUTHOR("Vladislav Bogdanov");

/* you are my reggae untouchable */
