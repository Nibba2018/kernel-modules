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
static int arr_argc = 0;
static int myIntArr[5] = {0, 0, 0, 0, 0};

module_param(howmany, int, S_IRUGO);
module_param(whom, charp, S_IRUGO);
module_param_array(myIntArr, int, &arr_argc, S_IRUGO);

// Function to run when module is loaded.
static int hello_init(void)
{
	int i;
	for(i = 0; i < howmany; i++)
		printk(KERN_ALERT "Hello %s for %d time.\n", whom, i);

	for(i = 0; i<(sizeof(myIntArr)/sizeof(int)); i++)
		printk(KERN_ALERT "Value of Array[%d] = %d\n", i, myIntArr[i]);

	printk(KERN_ALERT "Received %d arguments\n", arr_argc);

	return 0;
}

// Function to run when module is unloaded. 
static void hello_exit(void)
{
	printk(KERN_ALERT "Goodbye, World!\n");
}

module_init(hello_init);
module_exit(hello_exit);
