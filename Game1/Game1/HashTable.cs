using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HashTableProject
{
    // Hash table with fixed size. Does not handle collisions.
    class HashTable <TKey,TValue>
    {

        int nullHash = -1;

        HashNode[] array;

        struct HashNode
        {
            public int hash;
            public TValue data;
        }

        int arraySize;

        // Constructor with hash table size.
        // Hash table must be initialised with a constant size, as the hash index of values depends on the array size.
        // Does not allow for dynamic size changing of the hash table.
        public HashTable(int size)
        {
            arraySize = size;
            array = new HashNode[arraySize];
            Clear();
        }

        // Returns calculated index for the key based on its hash code.
        int Hash(TKey key)
        {
            return Math.Abs(key.GetHashCode());
        }

        int GetIndex(int hash)
        {
            return hash % arraySize;
        }

        // Adds value into key hash position.
        public void Add(TKey key, TValue value)
        {
            int hash = Hash(key);
            int index = GetIndex(hash);

            for (int i=index;i<arraySize;i++)
            {
                if (!ExistsAt(i))
                {
                    array[i].data = value;
                    array[i].hash = hash;
                    break;
                }
                    
            }
            
        }

        // Returns value at keys hash index
        public TValue Get(TKey key)
        {

            int keyHash = Hash(key);

            int index = GetIndex(keyHash);

            if (ExistsAt(index))
            {
                for (int i=0;i<arraySize;i++)
                {
                    // Start cycling through entire array for the value until it is found or you reach arraySize elements
                    if (!object.Equals(keyHash, array[index].hash))
                    {
                        index += 1;
                        index %= arraySize;
/*
                        if (object.Equals(keyHash, array[index].hash))
                        {
                            return array[index].data;
                        }
                        */
                    }
                    else
                    {
                        return array[index].data;
                    }
                }
                
            }
            
    
            return default(TValue);
            
        }

        // Clears hash table
        public void Clear()
        {
            for (int i = 0; i < arraySize; i++)
            {
                array[i].data = default(TValue);
                array[i].hash = nullHash;
            }
        }

        public bool ContainsKey(TKey key)
        {
            /*
            // More efficient but did not work.
            
            if(array[GetIndex(key)] !=null)
            {
                return true;
            }
            return false;
            */
            
            for (int i = 0; i < arraySize; i++)
            {
                if (Equals(i,key))
                {
                    if(Equals(array[GetIndex(Hash(key))].hash,Hash(key)))
                    {
                        return true;
                    }
                    
                }
            }
            return false;
            
        }

        public bool ContainsValue(TValue value)
        {
            for (int i=0;i<arraySize;i++)
            {
                if(!object.Equals(array[i].hash,nullHash)&&object.Equals(array[i].data, value))
                {
                    return true;
                }
            }
            return false;
        }

        public bool ExistsAt(int index)
        {
            if (!object.Equals(array[index].hash,nullHash))
            {
                return true;
            }
            return false;
        }

        public void Remove(TKey key)
        {
            array[GetIndex(Hash(key))].data = default(TValue);
            array[GetIndex(Hash(key))].hash = -1;
        }

        public string Print()
        {
            string print = "";
            for(int i=0;i<arraySize;i++)
            {
                if(ExistsAt(i))
                {

                    print = print + array[i].data +",";
                }
            }
            return print;
        }

        
    }
}

