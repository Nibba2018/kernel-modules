#include<linux/init.h>
#include<linux/module.h>
#include<linux/stat.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Soham Biswas");
MODULE_DESCRIPTION("Kernel Module Hello World!");
MODULE_VERSION("0.1");

// Adding default values to params.
static char *whom = "World";
static int howmany = 1;

module_param(howmany, int, S_IRUGO);
module_param(whom, charp, S_IRUGO);

// Function to run when module is loaded.
static int hello_init(void)
{
	int i;
	for(i = 0; i<howmany; i++)
		printk(KERN_ALERT "Hello %s for %d time.\n", whom, i);

	return 0;
}

// Function to run when module is unloaded. 
static void hello_exit(void)
{
	printk(KERN_ALERT "Goodbye, World!\n");
}

module_init(hello_init);
module_exit(hello_exit);
