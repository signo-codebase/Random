/**
 * prende in ingresso una parola a 4 bit
 * restituisce una parola a 12 bit con ridondanza e complemento
 * se b0 è il LSB della parola allora
 * nella parola in codice si ha c0=b0, c1=~b0, c2=b0 (bit, complemento, copia bit)
 **/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> // serve per convertire l'input da string a int

//#define NDEBUG
/** l'operazione di debug viene eseguita se commento #define NDEBUG
 * 
 *  #ifndef NDEBUG
 *    operazione di debug
 *  #endif
 */

uint8_t *estrai_bit(uint8_t); // ritorna un vettore di 4 elementi, i bit da codificare
uint8_t get_codeblock(uint8_t); // calcola il blocco codificato per il bit
uint16_t get_codeword(uint8_t*); // calcola la parola di codice, in ingresso vettore con i 4 blocchi

int main(int argc, char *argv[]){

    // controllo che ci sia solo un input
    if (argc != 2)
    {
        return 1;
    }

    uint8_t parola = atoi(argv[1]);

    if (parola < 0 || parola > 15)
    {
        printf("Inserire un nemero da 0 al 15\n");
        return 1;
    }

    #ifndef NDEBUG
        printf("Input: %d\n", parola);
    #endif

    uint8_t *bitVec = estrai_bit(parola);
    uint8_t blocks[4];

    for (uint8_t i = 0; i < 4; i++)
    {
        blocks[i] = get_codeblock((bitVec[i] >> i));
    }

    uint16_t codeword = get_codeword(blocks);
    printf("Codeword decimale: %hu\n", codeword);
    printf("Codeword hex: %x\n", (int)codeword);

    return 0;
}


uint8_t *estrai_bit(uint8_t parola){

    static uint8_t bitVec[4];

    bitVec[0] = (parola & 0b1);

    #ifndef NDEBUG
        printf("bitVec[0]: %d\n", bitVec[0]);
    #endif

    bitVec[1] = (parola & (0b1<<1));

    #ifndef NDEBUG
        printf("bitVec[1]: %d\n", bitVec[1]);
    #endif

    bitVec[2] = (parola & (0b1<<2));

    #ifndef NDEBUG
        printf("bitVec[2]: %d\n", bitVec[2]);
    #endif

    bitVec[3] = (parola & (0b1<<3));

    #ifndef NDEBUG
        printf("bitVec[3]: %d\n", bitVec[3]);
    #endif

    return bitVec;
}

uint8_t get_codeblock(uint8_t bit){

    if (bit == 0b1)
    {
        return 0b101;
    }
    else if (bit == 0b0)
    {
        return 0b010;
    }
    else
    {
        #ifndef NDEBUG
            printf("GENERATO UN BLOCK ERRATO\n");
        #endif
        return 1;
    }
}

uint16_t get_codeword(uint8_t *blocks){

    uint16_t codeword = (0b1111<<12); // preambolo per capire se è codificata

    #ifndef NDEBUG
        printf("Codeword solo preambolo: %hu\n", codeword);
    #endif

    codeword += (uint16_t)(blocks[3] << 9) 
              + (uint16_t)(blocks[2] << 6) 
              + (uint16_t)(blocks[1] << 3) 
              + (uint16_t)blocks[0];

    return codeword;
}