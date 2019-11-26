#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include <stdbool.h>

using namespace std;

struct Attack{
    int min_atk;
    int max_atk;
};

struct Enemy{
    string name;
    int health;
    Attack atk;
    int dropcoin;
    int give_hero_health;
    bool last_enemy;
};

struct Weapon{
    string name;
    int stat_atk;
};

struct Hero{
    int health;
    int coins;
    Attack atk;
    Weapon equip;
};

int random_val(int rndm){
    return (rand()%rndm);
}

int random_attack(Attack atk){
    int val=0, rentang = atk.max_atk-atk.min_atk;
    val = random_val(rentang);
    return val + atk.min_atk;
}

int random_drop_coin(int dropcoin){
    int val=0, rentang = dropcoin/10;
    val = random_val(rentang);
    return val + (dropcoin/2);
}

Weapon random_weapon(string list_of_weapon[]){
    Weapon ret;
    int idx = random_val(3);
    ret.name = list_of_weapon[idx];
    ret.stat_atk = random_val(200);
    return ret;
}

int main()
{
    cout << "INTRO" << endl;
    cout << endl;
    cout << endl;
    system("pause");
    system("cls");
    cout << "putri raja di curi oleh raja iblis" << endl;
    cout << endl;
    cout << endl;
    system("pause");
    system("cls");
    cout << "anda sebagai adventure terkuat mendapat tugas dari baginda raja" << endl;
    cout << endl;
    cout << endl;
    system("pause");
    system("cls");
    cout << "untuk menyelamatkan putri dari raja iblis" << endl;
    cout << endl;
    cout << endl;
    system("pause");
    system("cls");
    cout << "untuk itu anda akan memulai petualangan anda" << endl;
    cout << endl;
    cout << endl;
    system("pause");
    system("cls");

    cout << "Hello welcome to batle world adventure!" << endl;
    cout << endl;
    /** end of intro */

    srand((unsigned)time(0));

    /** start of enemy stats list */
    Attack slime_atk;
    slime_atk.min_atk = 1;
    slime_atk.max_atk = 5;
    Enemy slime;
    slime.name = "Slime Kecil";
    slime.atk = slime_atk;
    slime.health = 50;
    slime.dropcoin = 10;
    slime.give_hero_health = 500;
    slime.last_enemy = false;

    Attack goblin_atk;
    goblin_atk.min_atk = 50;
    goblin_atk.max_atk = 75;
    Enemy goblin;
    goblin.name = "Goblin Hijau";
    goblin.atk = goblin_atk;
    goblin.health = 250;
    goblin.dropcoin = 30;
    goblin.give_hero_health = 1000;
    goblin.last_enemy = false;

    Attack lizardmen_atk;
    lizardmen_atk.min_atk = 200;
    lizardmen_atk.max_atk = 275;
    Enemy lizardmen;
    lizardmen.name = "Lizardmen";
    lizardmen.atk = lizardmen_atk;
    lizardmen.health = 1500;
    lizardmen.dropcoin = 70;
    lizardmen.give_hero_health = 5000;
    lizardmen.last_enemy = false;

    Attack minotaur_atk;
    minotaur_atk.min_atk = 400;
    minotaur_atk.max_atk = 500;
    Enemy minotaur;
    minotaur.name = "Minotaur";
    minotaur.atk = minotaur_atk;
    minotaur.health = 4000;
    minotaur.dropcoin = 150;
    minotaur.give_hero_health = 10000;
    minotaur.last_enemy = false;

    Attack king_atk;
    king_atk.min_atk = 1000;
    king_atk.max_atk = 1500;
    Enemy king;
    king.name = "Raja Iblis";
    king.atk = king_atk;
    king.health = 10000;
    king.dropcoin = 1000;
    king.give_hero_health = 0;
    king.last_enemy = true;
    /** end of enemy stats list */

    /** start of hero stats */
    Attack hero_start;
    hero_start.min_atk = 1;
    hero_start.max_atk = 10;
    Weapon no_weapon;
    no_weapon.name = "Tanpa Senjata";
    no_weapon.stat_atk = 0;
    Hero player;
    player.health = 100;
    player.coins = 0;
    player.atk = hero_start;
    player.equip = no_weapon;
    /** end of hero stats */

    vector<Enemy> list_of_enemy;
    list_of_enemy.push_back(slime);
    list_of_enemy.push_back(goblin);
    list_of_enemy.push_back(lizardmen);
    list_of_enemy.push_back(minotaur);
    list_of_enemy.push_back(king);

    vector<Weapon> weapon_inventory;

    vector<Weapon>::iterator weapon_pointer;
    vector<Enemy>::iterator enemy_pointer;

    string list_of_weapon[3];
    list_of_weapon[0] = "Pisau";
    list_of_weapon[1] = "Tombak";
    list_of_weapon[2] = "Pedang";

    int pilihan=1;
    int level;
    int shop;
    int monster;
    int monsterhealth;

    /** debug function */
//    cout << random_attack(lizardmen_atk) << endl;
//    cout << random_attack(goblin_atk) << endl;
//    cout << random_attack(lizardmen_atk) << endl;
//    cout << random_drop_coin(slime.dropcoin) << endl;
//    cout << random_drop_coin(minotaur.dropcoin) << endl;
//    cout << random_drop_coin(minotaur.dropcoin) << endl;
//    Weapon tries = random_weapon(list_of_weapon);
//    cout << tries.name << " " << tries.stat_atk << endl;
//    weapon_inventory.push_back(tries);
//    enemy_pointer = list_of_enemy.begin();
//    int tes = enemy_pointer->health;
//    tes -= 30;
//    cout << tes << " " << enemy_pointer->health << endl;
//    cout << player.health << endl;
//    player.health -= 10;
//    cout << player.health << endl;
    /** debug function */

while(pilihan!=0){

    cout << "Kondisi Pemain" << endl;
    cout << "Health: " << player.health << endl;
    cout << "Attack: " << player.atk.min_atk << " - " << player.atk.max_atk << endl;
    cout << "Weapon: " << player.equip.name << ": " << player.equip.stat_atk << endl;
    cout << "Coins: " << player.coins << endl;
    cout << endl;
    cout << "1. tampilkan status penuh" << endl;
    cout << "2. ganti weapon" << endl;
    cout << "3. lawan monster" << endl;
    cout << "4. mengunjungi weapon shop" << endl;
    cout << "0. keluar" << endl;
    cout<<"Apa yang ingin kamu lakukan?:";cin>>pilihan;
    system("cls");
    switch(pilihan)
    {
    case 1:
            cout << "Kondisi Pemain" << endl;
            cout << "Health: " << player.health << endl;
            cout << "Attack: " << player.atk.min_atk << " - " << player.atk.max_atk << endl;
            cout << "Coins: " << player.coins << endl;
            cout << endl;
            cout << "Inventory Weapon :" << endl;
            for(weapon_pointer=weapon_inventory.begin(); weapon_pointer!=weapon_inventory.end(); ++weapon_pointer){
                cout << "- " << weapon_pointer->name << " | stat: " << weapon_pointer->stat_atk << endl;
            }
            cout << endl;
            system("pause");
            system("cls");
            break;
    case 2:
            int index_weapon;
            int pilihan_w;
            cout << "Inventory Weapon :" << endl;
            for(weapon_pointer=weapon_inventory.begin(); weapon_pointer!=weapon_inventory.end(); ++weapon_pointer){
                cout << "- " << weapon_pointer->name << " | stat: " << weapon_pointer->stat_atk << endl;
            }
            cout << "Pilih index weapon: "; cin >> index_weapon;
            weapon_pointer = weapon_inventory.begin()+(index_weapon-1);
            system("cls");
            cout << "Gunakan / buang senjata ini?" << endl;
            cout << weapon_pointer->name << " | stat: " << weapon_pointer->stat_atk << endl;
            cout << "1. Gunakan" << endl;
            cout << "2. Buang" << endl;
            cout << "Tentukan pilihan: "; cin >> pilihan_w;
            switch(pilihan_w){
            case 1:
                {
                Weapon idx_w;
                idx_w.name = weapon_pointer->name;
                idx_w.stat_atk = weapon_pointer->stat_atk;
                player.equip = idx_w;
                break;
                }
            case 2:
                weapon_inventory.erase( weapon_inventory.begin()+(index_weapon-1) );
                break;
            }
            system("cls");
            break;
    case 3:
    {
        int index_enemy;
        cout << "welcome to monster nest!" << endl;
        cout << "pilih monster yang ingin di lawan " << endl;
        int i=1;
        for(enemy_pointer=list_of_enemy.begin(); enemy_pointer!=list_of_enemy.end(); ++enemy_pointer){
            cout << i++ << ". " << enemy_pointer->name << endl;
        }
        cout << "0. kembali ke menu utama" << endl;
        cout << "Pilih Monster:"; cin >> index_enemy;
        system("cls");

        int battlestat = 1;
        int pilihan_battle = 1;
        enemy_pointer = list_of_enemy.begin()+(index_enemy-1);
        int enemy_health = enemy_pointer->health;
        while(battlestat){
            cout << "Bertarung melawan " << enemy_pointer->name << endl;
            cout << endl;
            cout << "Kondisi Player: " << endl;
            cout << "Health: " << player.health << endl;
            cout << "|" <<endl;
            cout << "|" <<endl;
            cout << "|" <<endl;
            cout << "|" <<endl;
            cout << "Kondisi Monster: " << endl;
            cout << "Health: " << enemy_health << endl;
            cout << "|" <<endl;
            cout << "|" <<endl;
            cout << "Pilihan:" <<endl;
            cout << "1. Serang" <<endl;
            cout << "2. Kabur" <<endl;
            cout << "Tentukan Pilihan:"; cin >> pilihan_battle;
            switch(pilihan_battle){
            case 1:
                enemy_health -= random_attack(player.atk) + player.equip.stat_atk;
                if(enemy_health>0){
                    player.health -= random_attack(enemy_pointer->atk);
                    if( player.health<=0 ){
                        system("cls");
                        char pilihan_lagi;
                        cout << "Game Over" << endl;
                        cout << endl;
                        cout << "Anda kalah di tengah permainan" << endl;
                        cout << "Main Lagi? (y/n): "; cin >> pilihan_lagi;
                        switch(pilihan_lagi){
                        case 'y':
                            battlestat = 0;
                            player.atk = hero_start;
                            player.health = 100;
                            player.equip = no_weapon;
                            player.coins = 0;
                            break;
                        case 'n':
                            return 0;
                            break;
                        }
                    }
                }else{
                    system("cls");
                    battlestat = 0;
                    if( !(enemy_pointer->last_enemy) ){
                        cout << "Anda berhasil mengalahkan " << enemy_pointer->name << endl;
                        int get_coin = random_drop_coin(enemy_pointer->dropcoin);
                        player.coins += get_coin;
                        cout << "Anda mendapatkan " << get_coin << " coin" << endl;
                        Weapon get_weapon = random_weapon(list_of_weapon);
                        weapon_inventory.push_back(get_weapon);
                        cout << "Anda mendapatkan " << get_weapon.name << " dengan stat " << get_weapon.stat_atk << endl;
                        if(player.health < enemy_pointer->give_hero_health){
                            player.health = enemy_pointer->give_hero_health;
                            cout << "Health Anda menjadi " << enemy_pointer->give_hero_health << endl;
                        }
                        enemy_pointer = list_of_enemy.begin()+(index_enemy);
                        player.atk = enemy_pointer->atk;
                        system("pause");
                        system("cls");
                    }else{
                        cout << "Selamat anda berhasil menyelamatkan sang putri" << endl;
                        cout << "Anda mengembalikan putri raja" << endl;
                        cout << "sang putri jatuh cinta kepada anda" << endl;
                        cout << "anda juga mencintai putri" << endl;
                        cout << "anda menikahi sang putri" << endl;
                        cout << "Tamat" << endl;
                        return 0;
                    }
                }
                break;
            case 2:
                battlestat = 0;
                break;
            default:
                break;
            }
            system("cls");
        }
            system("cls");
            break;
    }
    case 4:
        int pilihan_shop;
        cout << "welcome to weapon shop!" << endl;
        cout << "Status senjata yang di jual sama semua " << endl;
        cout << "jangan kawatir setiap kamu naik level status senjata di shop akan naik " << endl;
        cout << "semua senjata seharga 500 coins " << endl;
        for(int i=0; i<3; i++){
            cout << i+1 << list_of_weapon[i] << endl;
        }
        cout << "0.kembali ke menu utama" << endl;
        cout << "Masukkan pilihan: "; cin >> pilihan_shop;

        if( player.coins>=500 ){
            Weapon get_weap;
            int tt = pilihan_shop-1;
            get_weap.name = list_of_weapon[tt];
            get_weap.stat_atk = random_val(100)+200;
            weapon_inventory.push_back(get_weap);
            player.coins -= 500;
            system("cls");
            cout << endl;
            cout << endl;
            cout << "Anda telah membeli " << get_weap.name << " dengan stat " << get_weap.stat_atk << endl;
            cout << endl;
            cout << endl;
            system("pause");
        }else{
            system("cls");
            cout << endl;
            cout << endl;
            cout << "Maaf, tidak terima bon atau utang" << endl;
            cout << endl;
            cout << endl;
            system("pause");
        }

        system("cls");
        break;
    case 5:
        player.coins += 999;
        break;
    case 6:
        player.health = 10000;
        player.atk = king_atk;
        break;
    }
}
    return 0;
}
