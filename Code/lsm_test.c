#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/security.h>
#include <linux/types.h>
#include <asm/uaccess.h>
#include <linux/fcntl.h>
#include <linux/uaccess.h>
#include <linux/file.h>
#include <linux/namei.h>

static int lsm_test_file_permission(struct file *file,int mask)
{

    return 0;
}

static struct security_operations lsm_test_security_ops = {
    .file_permission = lsm_test_file_permission,
};

static int __init lsm_file_init(void)
{    
    if(register_security(&lsm_test_security_ops)){
        printk("register error ..........\n");
        return -1;
    }
   
    printk("lsm_file init..\n ");
    return 0;
}

static void __exit lsm_file_exit(void)
{
    if(unregister_security(&lsm_test_security_ops)){
        printk("unregister error................\n");
        return ;
    }

    printk("module exit.......\n");
}

MODULE_LICENSE("GPL");
module_init(lsm_file_init);
module_exit(lsm_file_exit);