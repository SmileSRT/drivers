### 1. Скомпилировать символьный драйвер

```
aakorovichev@ubuntu-22-04:~/Projects/drivers/task_3/driver$ make
make -C /lib/modules/6.8.0-85-generic/build M=/home/aakorovichev/Projects/drivers/task_3/driver modules
make[1]: Entering directory '/usr/src/linux-headers-6.8.0-85-generic'
warning: the compiler differs from the one used to build the kernel
  The kernel was built by: aarch64-linux-gnu-gcc-13 (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0
  You are using:           gcc-13 (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0
  CC [M]  /home/aakorovichev/Projects/drivers/task_3/driver/driver.o
  MODPOST /home/aakorovichev/Projects/drivers/task_3/driver/Module.symvers
  CC [M]  /home/aakorovichev/Projects/drivers/task_3/driver/driver.mod.o
  LD [M]  /home/aakorovichev/Projects/drivers/task_3/driver/driver.ko
  BTF [M] /home/aakorovichev/Projects/drivers/task_3/driver/driver.ko
Skipping BTF generation for /home/aakorovichev/Projects/drivers/task_3/driver/driver.ko due to unavailability of vmlinux
make[1]: Leaving directory '/usr/src/linux-headers-6.8.0-85-generic'
```

### 2. Вставить в ядро

```
aakorovichev@ubuntu-22-04:~/Projects/drivers/task_3/driver$ sudo insmod driver.ko
[sudo] password for aakorovichev: 
aakorovichev@ubuntu-22-04:~/Projects/drivers/task_3/driver$ lsmod | grep driver
driver                 12288  0

[ 6994.476972] INFO! start init module custom driver

aakorovichev@ubuntu-22-04:~/Projects/drivers/task_3/driver$ cat /proc/devices | grep foo
236 foo
```

### 3. Создать спец. файл устройства

```
aakorovichev@ubuntu-22-04:~/Projects/drivers/task_3/driver$ sudo mknod -m 660 /dev/driver-test-device c 236 0
aakorovichev@ubuntu-22-04:~/Projects/drivers/task_3/driver$ ls -l /dev | grep driver-test-device
crw-rw----  1 root         root    236,   0 Nov  3 01:35 driver-test-device
aakorovichev@ubuntu-22-04:~/Projects/drivers/task_3/driver$ 
```

### 4. Написать приолджения для открытия спец. файла устройства

```
aakorovichev@ubuntu-22-04:~/Projects/drivers/task_3/app$ gcc -o main main.c
aakorovichev@ubuntu-22-04:~/Projects/drivers/task_3/app$ ./main
Failed to open '/dev/driver-test-device': -1
aakorovichev@ubuntu-22-04:~/Projects/drivers/task_3/app$ sudo ./main
Opened '/dev/driver-test-device' device with fd=3
```

```
[ 6994.476972] INFO! start init module custom driver
[ 6994.476984] INFO! end init module custom driver
[ 7370.826997] INFO! Open device
[ 7370.827060] INFO! Release device
```