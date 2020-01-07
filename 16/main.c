#include "main.h"

int main() {
    struct termios save;
    struct termios tty;

    int fd = open("/dev/tty", O_RDONLY);
    char ch;

    if (!isatty(fd)) {
        exit(1);
    }

    tcgetattr(fd, &tty);
    save = tty;
    tty.c_lflag &= ~(ICANON|ISIG);
    tty.c_cc[VMIN] = 1;
    tcsetattr(fd, 0, &tty);
    char azaza[3][100];
    strcpy(azaza[0], "Rossiya svobodnaya strana? (phgahaha) [y/n]");
    strcpy(azaza[1], "Projitochniy minimum 20$/chas? [y/n]");
    strcpy(azaza[2], "Nebo ne goluboe? [y/n]");
    char answer[3] = {'n', 'n', 'y'};
    int i = 0;
    for (i = 0; i < 3; i++) {
	puts(azaza[i]);
        read(fd, &ch, 1);

        if (ch == answer[i])
            puts("\nCorrect!");
        else if (ch == 'n' || ch == 'y') {
            puts("\nNot a correct answer!");
        }
        else if (ch == 'q') {
            break;
        }
	else {
	    puts("\nNot a correct sym");
	}
    }

    tcsetattr(fd, 0, &save);

    return 0;
}


