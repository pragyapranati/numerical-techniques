#include <stdio.h>
#include <string.h>

long long powerMod(long long x, unsigned long long y, long long n) {
    long long result = 1;
    x = x % n;
    while (y > 0) {
        if (y & 1)
            result = (result * x) % n;
        y = y >> 1;
        x = (x * x) % n;
    }
    return result;
}

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void generateKeys(long long p, long long q, long long *n, long long *e, long long *d) {
    *n = p * q;
    long long phi = (p - 1) * (q - 1);
    for (*e = 2; *e < phi; (*e)++) {
        if (gcd(*e, phi) == 1)
            break;
    }
    for (*d = 1; (*d * (*e)) % phi != 1; (*d)++);
}

void encrypt(const char *msg, long long e, long long n, long long *cipher) {
    int i;
    for (i = 0; msg[i] != '\0'; i++) {
        cipher[i] = powerMod(msg[i], e, n);
    }
    cipher[i] = -1;
}

void decrypt(long long *cipher, long long d, long long n, char *decryptedMsg) {
    int i;
    for (i = 0; cipher[i] != -1; i++) {
        decryptedMsg[i] = (char)powerMod(cipher[i], d, n);
    }
    decryptedMsg[i] = '\0';
}

int main() {
    long long p, q, n, e, d;
    char msg[100], decryptedMsg[100];
    long long encryptedMsg[100];

    printf("Enter two prime numbers (p and q): ");
    scanf("%lld %lld", &p, &q);

    generateKeys(p, q, &n, &e, &d);
    printf("Public Key (e, n): (%lld, %lld)\n", e, n);
    printf("Private Key (d, n): (%lld, %lld)\n", d, n);

    printf("Enter message to encrypt: ");
    scanf(" %[^\n]", msg);

    encrypt(msg, e, n, encryptedMsg);
    printf("Encrypted message: ");
    for (int i = 0; encryptedMsg[i] != -1; i++) {
        printf("%lld ", encryptedMsg[i]);
    }
    printf("\n");

    decrypt(encryptedMsg, d, n, decryptedMsg);
    printf("Decrypted message: %s\n", decryptedMsg);

    return 0;
}
