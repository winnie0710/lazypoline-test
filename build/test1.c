
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // 開啟一個檔案進行測試
    const char *filename = "test_file.txt";
    int fd = open(filename, O_CREAT | O_WRONLY, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // 寫入一些內容
    const char *message = "Hello, lazypoline!";
    ssize_t bytes_written = write(fd, message, 18);
    if (bytes_written == -1) {
        perror("write");
        close(fd);
        return 1;
    }

    // 讀取剛才寫入的內容
    char buffer[20] = {0};
    lseek(fd, 0, SEEK_SET); // 將檔案指標移回開頭
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    // 輸出讀取的內容
    printf("Read from file: %s\n", buffer);

    // 關閉檔案
    close(fd);

    return 0;
}

