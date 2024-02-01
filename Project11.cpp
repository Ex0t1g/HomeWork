#include <cstdio>

int main() {
    FILE* fp = fopen("my.txt", "w");
    const char* phrase = "Mama myla ramu";
    int written = fwrite(phrase, sizeof(char), 13, fp);
    fclose(fp);

    return 0;
}
