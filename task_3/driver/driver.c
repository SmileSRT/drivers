#include <linux/fs.h>
#include <linux/module.h> /* Needed by all modules */
#include <linux/printk.h> /* Needed for pr_info() */

static int device_open(struct inode *inode, struct file *file) {
  pr_info("INFO! Open device\n");
  return 0;
}

static int device_release(struct inode *inode, struct file *file) {
  pr_info("INFO! Release device\n");
  return 0;
}

const struct file_operations fops = {
    //   .read = device_read,
    //   .write = device_write,
    .open = device_open,
    .release = device_release};

unsigned int Major;

int init_module(void) {
  pr_info("INFO! start init module custom driver");

  Major = register_chrdev(0, "foo", &fops);
  if (Major < 0) {
    printk(KERN_ALERT "Registering char device failed with %d\n", Major);
    return Major;
  }

  pr_info("INFO! end init module custom driver");

  /* A non 0 return means init_module failed; module can't be loaded. */
  return 0;
}

void cleanup_module(void) {
  pr_info("Goodbye world 1.\n");
  unregister_chrdev(Major, "foo");
}

MODULE_LICENSE("GPL");