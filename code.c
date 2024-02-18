#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100

void createFile(char *filename);
void deleteFile(char *filename);
void duplicateFile(char *source, char *destination);
void moveFile(char *source, char *destination);
void listFiles(char *directory);
void searchFile(char *directory, char *filename);

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char source[MAX_FILENAME_LENGTH];
    char destination[MAX_FILENAME_LENGTH];
    char directory[MAX_FILENAME_LENGTH];

    int choice;

    while (1) {
        printf("\nFile Manager Menu:\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Duplicate File\n");
        printf("4. Move File\n");
        printf("5. List Files in Directory\n");
        printf("6. Search File\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the filename to create: ");
                scanf("%s", filename);
                createFile(filename);
                break;
            case 2:
                printf("Enter the filename to delete: ");
                scanf("%s", filename);
                deleteFile(filename);
                break;
            case 3:
                printf("Enter the source filename to duplicate: ");
                scanf("%s", source);
                printf("Enter the destination filename: ");
                scanf("%s", destination);
                duplicateFile(source, destination);
                break;
            case 4:
                printf("Enter the source filename to move: ");
                scanf("%s", source);
                printf("Enter the destination filename: ");
                scanf("%s", destination);
                moveFile(source, destination);
                break;
            case 5:
                printf("Enter the directory to list files: ");
                scanf("%s", directory);
                listFiles(directory);
                break;
            case 6:
                printf("Enter the directory to search files: ");
                scanf("%s", directory);
                printf("Enter the filename to search: ");
                scanf("%s", filename);
                searchFile(directory, filename);
                break;
            case 0:
                printf("Exiting File Manager. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void createFile(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        fclose(file);
        printf("File already exists. Cannot create.\n");
    } else {
        file = fopen(filename, "w");
        fclose(file);
        printf("File created successfully.\n");
    }
}

void deleteFile(char *filename) {
    if (remove(filename) == 0) {
        printf("File deleted successfully.\n");
    } else {
        printf("Error deleting the file.\n");
    }
}

void duplicateFile(char *source, char *destination) {
    FILE *sourceFile = fopen(source, "r");
    FILE *destinationFile = fopen(destination, "w");

    if (sourceFile == NULL || destinationFile == NULL) {
        printf("Error duplicating file.\n");
        return;
    }

    char ch;
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destinationFile);
    }

    fclose(sourceFile);
    fclose(destinationFile);

    printf("File duplicated successfully.\n");
}

void moveFile(char *source, char *destination) {
    if (rename(source, destination) == 0) {
        printf("File moved successfully.\n");
    } else {
        printf("Error moving the file.\n");
    }
}

void listFiles(char *directory) {
    char command[MAX_FILENAME_LENGTH + 20];
    sprintf(command, "ls -l %s", directory);
    system(command);
}

void searchFile(char *directory, char *filename) {
    char command[MAX_FILENAME_LENGTH + MAX_FILENAME_LENGTH + 30];
    sprintf(command, "find %s -name %s", directory, filename);
    system(command);
}
