/* hello.c */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static char *whom = "world";
module_param(whom, charp, 0);

static int howmuch = 3;
module_param(howmuch, int, 0);

static int __init hello_init(void)
{
    int i;
    
    for (i = 0; i < howmuch; i++)
        pr_alert("(%d)Hello, %s!\n", i, whom);
    return 0;
}

static void __exit hello_exit(void)
{
    pr_alert("Goodbye, zlyuka!\n");
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Hello-world or greeting module");
MODULE_AUTHOR("Vladislav Bogdanov");
MODULE_VERSION("0.01");
