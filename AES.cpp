#include <iostream>

using namespace std;

int s_box[256] =  
 {0x63 ,0x7c ,0x77 ,0x7b ,0xf2 ,0x6b ,0x6f ,0xc5 ,0x30 ,0x01 ,0x67 ,0x2b ,0xfe ,0xd7 ,0xab ,0x76
 ,0xca ,0x82 ,0xc9 ,0x7d ,0xfa ,0x59 ,0x47 ,0xf0 ,0xad ,0xd4 ,0xa2 ,0xaf ,0x9c ,0xa4 ,0x72 ,0xc0
 ,0xb7 ,0xfd ,0x93 ,0x26 ,0x36 ,0x3f ,0xf7 ,0xcc ,0x34 ,0xa5 ,0xe5 ,0xf1 ,0x71 ,0xd8 ,0x31 ,0x15
 ,0x04 ,0xc7 ,0x23 ,0xc3 ,0x18 ,0x96 ,0x05 ,0x9a ,0x07 ,0x12 ,0x80 ,0xe2 ,0xeb ,0x27 ,0xb2 ,0x75
 ,0x09 ,0x83 ,0x2c ,0x1a ,0x1b ,0x6e ,0x5a ,0xa0 ,0x52 ,0x3b ,0xd6 ,0xb3 ,0x29 ,0xe3 ,0x2f ,0x84
 ,0x53 ,0xd1 ,0x00 ,0xed ,0x20 ,0xfc ,0xb1 ,0x5b ,0x6a ,0xcb ,0xbe ,0x39 ,0x4a ,0x4c ,0x58 ,0xcf
 ,0xd0 ,0xef ,0xaa ,0xfb ,0x43 ,0x4d ,0x33 ,0x85 ,0x45 ,0xf9 ,0x02 ,0x7f ,0x50 ,0x3c ,0x9f ,0xa8
 ,0x51 ,0xa3 ,0x40 ,0x8f ,0x92 ,0x9d ,0x38 ,0xf5 ,0xbc ,0xb6 ,0xda ,0x21 ,0x10 ,0xff ,0xf3 ,0xd2
 ,0xcd ,0x0c ,0x13 ,0xec ,0x5f ,0x97 ,0x44 ,0x17 ,0xc4 ,0xa7 ,0x7e ,0x3d ,0x64 ,0x5d ,0x19 ,0x73
 ,0x60 ,0x81 ,0x4f ,0xdc ,0x22 ,0x2a ,0x90 ,0x88 ,0x46 ,0xee ,0xb8 ,0x14 ,0xde ,0x5e ,0x0b ,0xdb
 ,0xe0 ,0x32 ,0x3a ,0x0a ,0x49 ,0x06 ,0x24 ,0x5c ,0xc2 ,0xd3 ,0xac ,0x62 ,0x91 ,0x95 ,0xe4 ,0x79
 ,0xe7 ,0xc8 ,0x37 ,0x6d ,0x8d ,0xd5 ,0x4e ,0xa9 ,0x6c ,0x56 ,0xf4 ,0xea ,0x65 ,0x7a ,0xae ,0x08
 ,0xba ,0x78 ,0x25 ,0x2e ,0x1c ,0xa6 ,0xb4 ,0xc6 ,0xe8 ,0xdd ,0x74 ,0x1f ,0x4b ,0xbd ,0x8b ,0x8a
 ,0x70 ,0x3e ,0xb5 ,0x66 ,0x48 ,0x03 ,0xf6 ,0x0e ,0x61 ,0x35 ,0x57 ,0xb9 ,0x86 ,0xc1 ,0x1d ,0x9e
 ,0xe1 ,0xf8 ,0x98 ,0x11 ,0x69 ,0xd9 ,0x8e ,0x94 ,0x9b ,0x1e ,0x87 ,0xe9 ,0xce ,0x55 ,0x28 ,0xdf
 ,0x8c ,0xa1 ,0x89 ,0x0d ,0xbf ,0xe6 ,0x42 ,0x68 ,0x41 ,0x99 ,0x2d ,0x0f ,0xb0 ,0x54 ,0xbb ,0x16};


    void aes_encrypt(unsigned char* message, unsigned char* key);
    void key_expand();
    void byte_sub(unsigned char* state_matrix);
    void shift_rows(unsigned char* state_matrix);             
    void add_roundkey(unsigned char* state_matrix, unsigned char* roundkey);
    void mix_columns();
    void rem_rounds();






int main(void)
{
    unsigned char message[] = "message";
    unsigned char key[] = "key";
        aes_encrypt(message,key);

}


void aes_encrypt (unsigned char* message, unsigned char* key)
{

    unsigned char* state_matrix[16];
    
        for(int i = 0; i < 16; i++)
        {
            state_matrix[i] = message[i];

        }
    key_expand();
    add_roundkey(state_matrix, key);
    rem_rounds();



    key_expand();

    int numberofrounds = 10;
    key_expand();
    add_roundkey();
    
    for(int i = 0; i < numberofrounds; i++)
    {
        byte_sub(state_matrix);
        shift_rows(state_matrix);
        mix_columns();
        add_roundkey(state_matrix,key);
    }
        byte_sub(state_matrix);
        shift_rows(state_matrix);
        add_roundkey(state_matrix, key);
}

    void key_expand()
{

}



void rem_rounds()

{

}





    void byte_sub (unsigned char* state_matrix)
    {
        for( int i = 0; i < 16; i++)
        {
            state_matrix[i] = s_box[state_matrix[i]];
        }
    }



    void shift_rows(unsigned char* state_matrix)                    // Note: shift rows can be done with loops for simplicity we used direct method
    {
        unsigned char temp[16];

        temp[0] = state_matrix[0];
        temp[1] = state_matrix[5];
        temp[2] = state_matrix[10];
        temp[3] = state_matrix[15];

        temp[4] = state_matrix[4];
        temp[5] = state_matrix[9];
        temp[6] = state_matrix[14];
        temp[7] = state_matrix[3];

        temp[8] = state_matrix[8];
        temp[9] = state_matrix[13];
        temp[10] = state_matrix[2];
        temp[11] = state_matrix[7];

        temp[12] = state_matrix[12];
        temp[13] = state_matrix[1];
        temp[14] = state_matrix[6];
        temp[15] = state_matrix[11];
        

             for (int i=0;i<16;i++)
            {
                state_matrix[i]=temp[i];
            }
    }


    void mix_columns(unsigned char* state_matrix)
    {
        tmp[0] = (unsigned char)(mul2[state_matrix[0]] ^ mul3[state_matrix[1]] ^ state_matrix[2] ^ state_matrix[3]);
        tmp[1] = (unsigned char)(state_matrix[0] ^ mul2[state_matrix[1]] ^ mul3[state_matrix[2]] ^ state_matrix[3]);
        tmp[2] = (unsigned char)(state_matrix[0] ^ state_matrix[1] ^ mul2[state_matrix[2]] ^ mul3[state_matrix[3]]);
        tmp[3] = (unsigned char)(mul3[state_matrix[0]] ^ state_matrix[1] ^ state_matrix[2] ^ mul2[state_matrix[3]]);

        tmp[4] = (unsigned char)(mul2[state_matrix[4]] ^ mul3[state_matrix[5]] ^ state_matrix[6] ^ state_matrix[7]);
        tmp[5] = (unsigned char)(state_matrix[4] ^ mul2[state_matrix[5]] ^ mul3[state_matrix[6]] ^ state_matrix[7]);
        tmp[6] = (unsigned char)(state_matrix[4] ^ state_matrix[5] ^ mul2[state_matrix[6]] ^ mul3[state_matrix[7]]);
        tmp[7] = (unsigned char)(mul3[state_matrix[4]] ^ state_matrix[5] ^ state_matrix[6] ^ mul2[state_matrix[7]]);

        tmp[8] = (unsigned char)(mul2[state_matrix[8]] ^ mul3[state_matrix[9]] ^ state_matrix[10] ^ state_matrix[11]);
        tmp[9] = (unsigned char)(state_matrix[8] ^ mul2[state_matrix[9]] ^ mul3[state_matrix[10]] ^ state_matrix[11]);
        tmp[10] = (unsigned char)(state_matrix[8] ^ state_matrix[9] ^ mul2[state_matrix[10]] ^ mul3[state_matrix[11]]);
        tmp[11] = (unsigned char)(mul3[state_matrix[8]] ^ state_matrix[9] ^ state_matrix[10] ^ mul2[state_matrix[11]]);

        tmp[12] = (unsigned char)(mul2[state[12]] ^ mul3[state[13]] ^ state[14] ^ state[15]);
        tmp[13] = (unsigned char)(state[12] ^ mul2[state[13]] ^ mul3[state[14]] ^ state[15]);
        tmp[14] = (unsigned char)(state[12] ^ state[13] ^ mul2[state[14]] ^ mul3[state[15]]);
        tmp[15] = (unsigned char)(mul3[state[12]] ^ state[13] ^ state[14] ^ mul2[state[15]]);

        for(int i = 0; i < 16; i++)
        {
            state_matrix[i] = tmp[i]
        }
    }


    void add_roundkey (unsigned char* state_matrix,unsigned char* roundkey)
    {
        for(int i = 0; i < 16; i++)
        {
            state_matrix[i] ^= roundkey[i];
        }
    }