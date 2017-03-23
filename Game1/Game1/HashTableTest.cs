using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;

// Hash table test.. decided to try to learn NUnit by testing some of these data structures as well as MyMath

namespace ConsoleApplication5
{
    [TestFixture]
    class HashTableTest
    {
        [TestCase(4)]
        [TestCase(5)]
        [TestCase(10)]
        // Hash table size passed in must => array size entered in hash table (4)
        public static void HTTestAddWithIntKey(int htSize)
        {

            int[] values = new int[] { 1, 2, 3, 4};
            string expected = "1,3,2,4,";
                
            Console.WriteLine("TEST Add");
            HashTable<int, int> hasht = new HashTable<int, int>(htSize);
            for (int i = 0; i < values.Length; i++)
            {
                hasht.Add(i, values[i]);
            }
            string str = hasht.Print();

            Console.WriteLine(str);

            for (int i = 0; i < values.Length; i++)
            {
                Assert.True(hasht.ContainsValue(values[i]));

            }

        }

        [TestCase(5)] // This case contains colliding keys. 
        [TestCase(10)] // This case contains colliding keys. 
        [TestCase(50)]
        [TestCase(100)]
        public static void HTTestAddWithStringKey(int htSize)
        {
            int[] values = new int[] { 346098,3415,3467,456 };

            Console.WriteLine("TEST Add");
            HashTable<string, int> hasht = new HashTable<string, int>(htSize);
            hasht.Add("heshg", 346098);
            hasht.Add("y", 3415);
            hasht.Add("djhry", 3467);
            hasht.Add("2t4f", 456);
            hasht.Add("h", 0);


            string str = hasht.Print();

            Console.WriteLine(str);

            for (int i=0;i<values.Length;i++)
            {
                Assert.True(hasht.ContainsValue(values[i]));

            }

        }
        

        /*
        private object[] testCaseInput =
        {
        new object[] {  new int[] { 1,2,3 }, "1,2,3"}
        //new object[] { 2000, 1, 1, false, "second", false }
        };
        */

        [TestCase(new int[] { 1, 2, 3 }, 5 ) ]
        [TestCase(new int[] { 193,4,634,5 }, 5 )]
        [TestCase(new int[] { 43, 1236136, 6234634, 5436 }, 100)]
        public static void HTTestAddIntArray(int [] values, int htSize)
        {
            Console.WriteLine("TEST Add");
            HashTable<int, int> hasht = new HashTable<int, int>(htSize);
            for(int i=0;i<values.Length;i++)
            {
                hasht.Add(i, values[i]);
            }

            for (int i = 0; i < values.Length; i++)
            {
                Assert.True(hasht.ContainsValue(values[i]));

            }

            string str = hasht.Print();
            Console.WriteLine(str);
            
        }
        
        [Test]
        public static void HTTestExistsAt()
        {
            HashTable<int, int> hasht = new HashTable<int, int>(10);

            hasht.Add(1, 304);
            Assert.True(hasht.ExistsAt(1));
            Assert.False(hasht.ExistsAt(0));
            Assert.False(hasht.ExistsAt(2));

        }
        

        [Test]
        public static void HTTestGet()
        {
            Console.WriteLine("TEST Get");
            int[] values = new int[] { 1, 2, 3, 4, 5, 6,7,8,9,10 };
            //int keyToGet = 3;
            string str = "";

            HashTable<int, int> hasht = new HashTable<int, int>(values.Length);
            for (int i = 0; i < values.Length; i++)
            {
                hasht.Add(i, values[i]);
            }
            for (int i = 0; i < values.Length; i++)
            {
                Assert.True(hasht.ContainsKey(i));
                str +=(hasht.Get(i) + ",");
            }
            string print = hasht.Print();
            Console.WriteLine(print);
            Console.WriteLine(str);

            Assert.True(!hasht.ContainsKey(9000));


            int val = hasht.Get(2);

            Assert.True(val == 3);

            //Console.WriteLine(hasht.Get(keyToGet));

            
        }

        [Test]
        public static void HTTestContainsValue()
        {

            Console.WriteLine("TEST Get");
            int[] values = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            //int keyToGet = 3;

            HashTable<int, int> hasht = new HashTable<int, int>(values.Length);
            for (int i = 0; i < values.Length; i++)
            {
                hasht.Add(i, values[i]);
            }
            for (int i = 0; i < values.Length; i++)
            {
                Console.Write(hasht.Get(i) + ",");
            }

            Assert.True(!hasht.ContainsValue(9000));
            Assert.True(!hasht.ContainsValue(0));
            Assert.True(!hasht.ContainsValue(11));

            for (int i = 1; i <= values.Length; i++)
            {
                Assert.True(hasht.ContainsValue(i));
            }

            
            Console.WriteLine(" "+hasht.Print());
        }
    }
}

            /*
        [Test]
        public static void TestGet<TVal>(TVal[] values, int keyToGet)
        {
            Console.WriteLine("TEST Get");
            HashTable<int, TVal> hasht = new HashTable<int, TVal>(5);
            for (int i = 0; i < values.Length; i++)
            {
                hasht.Add(i, values[i]);
            }

            if(hasht.ContainsKey(keyToGet))
            {
                Console.WriteLine(hasht.Get(keyToGet));
            }

            Console.WriteLine(hasht.Print());
            
        }
        */