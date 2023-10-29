function hashFunction(input, hashTable) {
    let index = input % hashTable.length;                          //index is assigned based on the hash-function on the RHS

    let i = 1;
    while (hashTable[index] !== null) {                            //if the array index is not null, i.e. occupied by other elements, the loop runs
        index = (index + i ** 2) % hashTable.length;               //new index is assigned based on quadratic probing.(old index plus i squared)
        i++;                                                       //% operation is used, incase the quadratic function gives a value out of bounds of the array
    }
    hashTable[index] = input;
}

function main() {
    let tableSize = 10;                                           //setting table size 
    let hashTable = Array(tableSize).fill(null);                  //initializing array and filling it with null
    let choice = "Y";
    while (choice == "Y") {

        if (!(hashTable.includes(null))) {                        //if hash table is full, the loop ends and program terminates
            alert("Table is full. PLease reset table size and re-enter the values.");
            break;
        }

        let input = prompt("Enter number to enter into hash table:");
        hashFunction(input, hashTable);

        console.log("Hash Table Indices:");                       //The hash table is printed out onto the log.
        let i = 0;
        while (i < tableSize) {
            console.log(i + ' ');
            i++;
        }

        i = 0;
        console.log("Hash Table Values:");
        while (i < tableSize) {
            console.log(hashTable[i] + ' ');
            i++;
        }

        choice = prompt("Do you want to continue?(Y/N)")
    }
}
//Contributed by Senthil Adithya github: a-dithya04
main();