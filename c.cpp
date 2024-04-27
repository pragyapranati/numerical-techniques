#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PRIME 250

int prime[MAX_PRIME];
int prime_count = 0;
int public_key;
int private_key;
int n;

void primefiller() {
    bool seive[MAX_PRIME];
    memset(seive, true, sizeof(seive));
    seive[0] = false;
    seive[1] = false;
    for (int i = 2; i < MAX_PRIME; i++) {
        if (seive[i]) {
            prime[prime_count++] = i;
            for (int j = i * 2; j < MAX_PRIME; j += i) {
                seive[j] = false;
            }
        }
    }
}

int pickrandomprime() {
    int k = rand() % prime_count;
    int ret = prime[k];
    for (int i = k; i < prime_count - 1; i++) {
        prime[i] = prime[i + 1];
    }
    prime_count--;
    return ret;
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void setkeys() {
    int prime1 = pickrandomprime();
    int prime2 = pickrandomprime();
    n = prime1 * prime2;
    int fi = (prime1 - 1) * (prime2 - 1);
    int e = 2;
    while (1) {
        if (gcd(e, fi) == 1)
            break;
        e++;
    }
    public_key = e;
    int d = 2;
    while (1) {
        if ((d * e) % fi == 1)
            break;
        d++;
    }
    private_key = d;
}

long long int encrypt(double message) {
    int e = public_key;
    long long int encrypted_text = 1;
    while (e--) {
        encrypted_text *= message;
        encrypted_text %= n;
    }
    return encrypted_text;
}

long long int decrypt(int encrypted_text) {
    int d = private_key;
    long long int decrypted = 1;
    while (d--) {
        decrypted *= encrypted_text;
        decrypted %= n;
    }
    return decrypted;
}

void encoder(char message[]) {
    printf("Initial message:\n%s\n\n", message);
    printf("The encoded message(encrypted by public key):\n");
    for (int i = 0; i < strlen(message); i++) {
        printf("%lld", encrypt((int)message[i]));
    }
    printf("\n\n");
}

void decoder(long long int encoded[]) {
    printf("The decoded message(decrypted by private key):\n");
    for (int i = 0; i < prime_count; i++) {
        printf("%c", decrypt(encoded[i]));
    }
    printf("\n");
}

int main() {
    primefiller();
    setkeys();
    char message[100];
    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    long long int encoded[strlen(message)];
    encoder(message);
    decoder(encoded);
    return 0;
}
