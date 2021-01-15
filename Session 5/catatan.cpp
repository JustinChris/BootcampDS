//Linear Probing

/*kalau kita pasang const, itu menandakan kalau variable itu read only
yang artinya kita ga pernah ubah variable itu
*/
#include <stdio.h>
#include <string.h>


const int MAX_ELEMENT = 5;
const int MAX_LENGTH = 255;
char HASHTABLES[MAX_ELEMENT][MAX_LENGTH];

int hash(const char *str) {    
    //ascii sum hash function
    //dengan anggapan bahwa a = 0, b = 1, c = 2 dst..
    // abcd = 1 + 2 + 3 + 4 = 10
    int sum = 0;

    for (int i = 0; str[i] != '\0';i++) {
        sum += str[i] - 'a';    // menjumlahkan ascii dari tiap karakter di dalam string
    }

    return sum % MAX_ELEMENT; //menghindarin index di luar batas
}

void linearProbing ( const char *str, int index) {
    // loop dari index+1 sampai index-1
    for (int i = (index+1) % MAX_ELEMENT; i != index; i = (i+1) % MAX_ELEMENT){
        if (!HASHTABLES[i][0]) {   //jika index masih kosong
            strcpy(HASHTABLES[index],str);  //masukin string ke hashtable
            return;
        }
    }
    puts("TABLE IS FULL");  //tidak berhasil memasukan string ke hastable
}
/*kalau msih bingung

if (hashtables[index][0] =='\0')
kita cek apakah index ini kosogn atau engga
dan hashtables ini adalah variable global, yang otomatis setiap index 0 di isi oleh \0
*/

void insert (const char *str) {
    int index = hash(str);  //dapetin index array lewat hash function

    if (!HASHTABLES[index][0]) {   //jika index masih kosong
        strcpy(HASHTABLES[index],str);
    }else { //jika sudah terisi
        linearProbing(str,index);   //lakukan linear probing
    }

    
}

void view() {
    for (int i = 0; i < MAX_ELEMENT;i++) {
        printf("Index %d: %s\n",i,HASHTABLES[i]);
    }

}



int main() {
insert("valdo");
insert ("Daniel");
insert("vincent");
insert("ahmad");
insert("budi");
view();


}