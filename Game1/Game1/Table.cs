using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using HashTableProject;

namespace Game1
{
    class Table<TKey, TValue>
    {
        Dictionary<TKey, TValue> m_data;
        public Table(int size)
        {
            m_data = new Dictionary<TKey, TValue>(size);
        }

        public void Add(TKey key, TValue value)
        {
            m_data.Add(key, value);
        }

        public TValue Get(TKey key)
        {
            return m_data[key];
        }

        public void Clear()
        {
            m_data.Clear();
        }

        public void Remove(TKey key)
        {
            m_data.Remove(key);
        }

        public bool ContainsKey(TKey key)
        {
            return m_data.ContainsKey(key);
        }

        public bool ContainsValue(TValue val)
        {
            return m_data.ContainsValue(val);
        }
    }

    /*

    /// <summary>
    /// Table class encapsulates hash table for use in game.
    /// </summary>
    /// <typeparam name="TKey"></typeparam>
    /// <typeparam name="TValue"></typeparam>
    class Table<TKey, TValue>
    {
        HashTable<TKey, TValue> m_data;
        public Table(int size)
        {
            m_data = new HashTable<TKey, TValue>(size);
        }

        public void Add(TKey key, TValue value)
        {
            m_data.Add(key, value);
        }

        public TValue Get(TKey key)
        {
            return m_data.Get(key);
        }

        public void Clear()
        {
            m_data.Clear();
        }

        public void Remove(TKey key)
        {
            m_data.Remove(key);
        }

        public bool ContainsKey(TKey key)
        {
            return m_data.ContainsKey(key);
        }

        public bool ContainsValue(TValue val)
        {
            return m_data.ContainsValue(val);
        }
    }

    */
}
