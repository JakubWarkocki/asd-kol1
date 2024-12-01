#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include "tests/Tester.hpp"
#include "structures/DataStruct.hpp"

bool Tester::testPriorityQueue(DataStruct& pq, unsigned seed, bool verbose, std::string name){
    
    srand(seed);

    int value, true_value;
    bool ok = true;
    std::vector<int> reference_values;

    if(verbose){
        std::cout << "PRIORITY QUEUE TEST FOR " << name << " WITH SEED: " << seed << std::endl;
        std::cout << "TESTING EMPTY QUEUE SAFEGUARDS..." << std::endl;
    }

    value = pq.delMax();

    if(value != NEGATIVE_INFINITY){
        if(verbose){
            std::cout << "EMPTY QUEUE SHOULD YIELD NEGATIVE INFINITY " << std::endl;
            std::cout << "CHECK IF THE PASSED PRIORITY QUEUE IS EMPTY" << std::endl;
        }
        return false;
    }

    if(verbose){
        std::cout << "EMPTY QUEUE SAFEGUARDS OK" << std::endl;
    }

    if(verbose){
        std::cout << "TESTING INSERT AND DELETE MAX..." << std::endl;
        std::cout << "INSERTING ELEMENTS:" << std::endl;
    }

    for(int i = 0; i < 25; i++){
        value = rand()%100;
        pq.insert(value);
        reference_values.push_back(value);

        if(verbose){
            std::cout << value << " ";
        }
    }

    std::sort(reference_values.begin(), reference_values.end(), std::greater<int>());

    if(verbose){
        std::cout << std::endl;
        std::cout << "RETRIEVING ELEMENTS: " << std::endl;
    }
;
    for(int i = 0; i < 25; i++){
        value = pq.delMax();

        if(value != reference_values[i]){
            ok = false;
        }

        if(verbose){
            std::cout << value << " ";
        }
    }    

    if(verbose){
        std::cout << std::endl;
    }

    if(!ok){

        if(verbose){
            std::cout << "RETRIEVAL ORDER ERROR" << std::endl;    
        }  
        return false;
    }

    if(verbose){
        std::cout << "RETRIEVAL ORDER OK" << std::endl;     
        std::cout << "TESTING IF QUEUE HAS BEEN PROPERLY EMPTIED..." << std::endl;    
    }  

    value = pq.delMax();
    if(value != NEGATIVE_INFINITY){
        ok = false;
    }
    pq.insert(-1);
    value = pq.delMax();    
    if(value != -1){
        ok = false;
    }

    if(!ok){
        if(verbose){
            std::cout << "QUEUE HAS NOT BEEN PROPERLY EMPTIED" << std::endl;    
        }
        return false;
    }

    if(verbose){
        std::cout << "ALL TESTS OK" << std::endl;    
    }  

    return true;

}

bool Tester::testDictionary(DataStruct& dc, unsigned seed, bool verbose, std::string name) {

    srand(seed);

    bool ok = true;
    int key, value, true_value;
    std::string valstr;
    if (verbose) {
        std::cout << "DICTIONARY TEST FOR " << name << " WITH SEED: " << seed << std::endl;
        std::cout << "TESTING EMPTY ENTRY SAFEGUARDS..." << std::endl;
    }

    if (dc.search(1) != NEGATIVE_INFINITY) {
        if (verbose) {
            std::cout << "SEARCING FOR NON EXISTENT ENTRY SHOULD RETURN NEGATIVE_INFINITY" << std::endl;
        }
        return false;
    }


    if (verbose) {
        std::cout << "NULL SEARCH SAFEGUARDS OK" << std::endl;
    }

    // Generowanie par kluczy i wartości

    int key_val_pairs[25][2];
    int unused_keys[25];
    int all_keys[100];

    for (int i = 0; i < 100; i++) {
        all_keys[i] = i + 1;
    }

    for (int i = 0; i < 100; i++) {
        int i2 = rand() % 100;
        std::swap(all_keys[i], all_keys[i2]);
    }

    for (int i = 0; i < 25; i++) {
        key_val_pairs[i][0] = all_keys[i];
        key_val_pairs[i][1] = rand() % 1000;
    }

    for (int i = 25; i < 50; i++) {
        unused_keys[i-25] = all_keys[i];
    }
 
    if (verbose) {
        std::cout << "TESTING INSERTION AND SEARCH..." << std::endl;
        std::cout << "INSERTING KEY-VALUE PAIRS:" << std::endl;
    }

    for (int i = 0; i < 25; i++) {
        dc.insert(key_val_pairs[i][0], key_val_pairs[i][1]);
        if(verbose){
            std::cout << "(" << key_val_pairs[i][0] << ", " << key_val_pairs[i][1] << ")" << std::endl;
        }
    }

    for (int i = 0; i < 25; i++) {
        int i2 = rand()%25;
        std::swap(key_val_pairs[i][0], key_val_pairs[i2][0]);
        std::swap(key_val_pairs[i][1], key_val_pairs[i2][1]);
    }

    if(verbose){
        std::cout << "SEARCHING USING KEYS:" << std::endl;
    }

    for (int i = 0; i < 50; i++) {

        if (i%2){
            key = key_val_pairs[i][0];
            true_value =  key_val_pairs[i][1];
        }
        else{
            key = unused_keys[i];
            true_value = NEGATIVE_INFINITY;
        }

        value = dc.search(key);

        if(verbose){
            if(value == NEGATIVE_INFINITY){
                valstr = "NOT FOUND";
            }
            std::cout << key << " -> " << valstr;
        }

        if(value != true_value){
            ok = false;
            if(verbose){
                std::cout << " [ERROR]" << std::endl;
            }
        }
        else{
             if(verbose){
                std::cout << " [OK]" << std::endl;
            }           
        }
    }

    if(!ok){
        if(verbose){
            std::cout << "INSERT AND SEARCH ERROR" << std::endl;
        }
        return false;
    }
    else{
        if(verbose){
            std::cout << "INSERT AND SEARCH ERROR" << std::endl;  
        }
    }

    for (int i = 0; i < 25; i++) {
        int i2 = rand()%25;
        std::swap(key_val_pairs[i][0], key_val_pairs[i2][0]);
        std::swap(key_val_pairs[i][1], key_val_pairs[i2][1]);
    }

    if (verbose) {
        std::cout << "TESTING DOUBLE INSERT SAFEGUARDS..." << std::endl;
    }

    for (int i = 0; i < 5; i++) {
        key = key_val_pairs[i][0];
        true_value = key_val_pairs[i][1];

        if(rand()%2){     
            value = true_value+rand()%10+1;
        }
        else{
            value = true_value-rand()%10-1;
        }

        dc.insert(key, value);

        if(verbose){
            std::cout << "(" << key << ", " << true_value << ") INSERTING " << "(" << key << ", " << value << ")" << std::endl;
        }

        value = dc.search(key);

        if(verbose){
            std::cout << "ATTEMPTING LOOKUP" << key << " -> " << value;        
        }

        if(value==true_value){
            if(verbose){
                std::cout << " [OK]" << std::endl;
            }
        }
        else{
            if(verbose){
                std::cout << " [ERROR]" << std::endl;
            }
            ok = false;
        } 
    }

    if(!ok){
        if(verbose){
            std::cout << "REINSERT ATTEMPTS ARE NOT PROPERLY BLOCKED" << std::endl;
        }
        return false;
    }
    else{
        if(verbose){
            std::cout << "RESINSERT BLOCKING OK" << std::endl;       
        }
    }

    if (verbose) {
        std::cout << "TESTING ELEMENT DELETION..." << std::endl;
    }

    for (int i = 0; i < 25; i++) {

        key = key_val_pairs[i][0];

        if(verbose){
            std::cout << "DELETING ELEMENT WITH KEY " << key; 
        }

        dc.delElement(key);
        value = dc.search(key);

        if(value != NEGATIVE_INFINITY){
            ok = false;
            if(verbose){
                std::cout << " [ERROR]" << std::endl;
            }
        }
        else{
            if(verbose){
                std::cout << " [OK]" << std::endl;
            }
        }
    }

    if (verbose) {
        std::cout << "ELEMENT DELETION OK" << std::endl;
    }

    if (verbose) {
        std::cout << "TESTING POST-DELETION REUSABILITY..." << std::endl;
    }

    key = 1;
    value = rand()%100;

    dc.insert(key, value);

    if(dc.search(key)!=value){
        if(verbose){
            std::cout << "ERROR" << std::endl;    
        }
        return false;      
    }
    else{
        if(verbose){
            std::cout << "OK" << std::endl;    
        }      
    }

    if (verbose) {
        std::cout << "ALL TESTS OK" << std::endl;
    }

    return true;
}
