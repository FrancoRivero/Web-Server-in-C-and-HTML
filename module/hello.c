#include <linux/module.h>
#include <linux/kernel.h>
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Modulo Hello world kernel module");
MODULE_AUTHOR("Rivero Franco");
int hello_init(void)
{
printk(KERN_ALERT "Hello World\n");
return 0;
}
void hello_exit(void)
{
printk(KERN_ALERT "Goodbye World\n");
}
module_init(hello_init);
module_exit(hello_exit);