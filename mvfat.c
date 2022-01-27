printf("using loop device: %s\n", loop_device);

file_fd = open("./Dos3.3.img", O_RDWR);
if (file_fd < 0) {
  perror("open backing file failed");
  return 1;
 }

device_fd = open(loop_device, O_RDWR);
if (device_fd < 0) {
  perror("open loop device failed");
  close(file_fd);
  return 1;
 }

if (ioctl(device_fd, LOOP_SET_FD, file_fd) < 0) {
  perror("ioctl LOOP_SET_FD failed");
  close(file_fd);
  close(device_fd);
  return 1;
 }

close(file_fd);

if (mount(loop_device, "./mnt/", "vfat", MS_DIRSYNC | MS_SYNCHRONOUS, "") < 0) {
  perror("mount failed");
 } else {
  printf("mount successful\n");
 }

// always free loop device in the end
ioctl(device_fd, LOOP_CLR_FD, 0);      
close(device_fd);
}
