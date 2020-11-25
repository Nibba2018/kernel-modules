#include<linux/init.h>
#include<linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Soham Biswas");
MODULE_DESCRIPTION("Kernel Module Hello World!");
MODULE_VERSION("0.1");

// Function to run when module is loaded.
static int hello_init(void)
{
	printk(KERN_ALERT "Hello, World!\n");
	return 0;
}

// Function to run when module is unloaded. 
static void hello_exit(void)
{
	printk(KERN_ALERT "Goodbye, World!\n");
}

module_init(hello_init);
module_exit(hello_exit);
