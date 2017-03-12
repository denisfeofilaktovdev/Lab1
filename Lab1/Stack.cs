using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LabForms1
{
    public class Stack
    {
        // Останній елемент стека
        private Carriage Last;
        // Кількість елементів стека
        public int Count;

        /// <summary>
        /// Формування першого вагона
        /// </summary>
        public Stack()
        {
            Count = 0;
        }

        #region Public Methods
        /// <summary>
        /// Метод додає новий елемент в стек
        /// </summary>
        public void Add()
        {
            if (Count != 0)
            {
                Carriage next = new Carriage {Previous = Last};

                next.SetNumber(Last.GetNumber() + 1);

                Last = next;
                Count++;
            }
            else FormList();
        }

        /// <summary>
        /// Метод додає в стек новий елемент із вказаним типом
        /// </summary>
        public void Add(string atype)
        {
            if (Count != 0)
            {
                Carriage Next = new Carriage(atype) {Previous = Last};

                Next.SetNumber(Last.GetNumber() + 1);

                Last = Next;
                Count++;
            }
            else FormList(atype);
        }

        /// <summary>
        /// Метод видаляє останній елемент стека
        /// </summary>
        public void RemoveLast()
        {
            if(Last != null)
                Last = Last.Previous;
        }

        /// <summary>
        /// Метод повертає останній елемент стека
        /// </summary>
        public Carriage GetLast()
        {
            return Last;
        }
        #endregion

        #region Private Methods
        /// <summary>
        /// Метод формує перший вагон
        /// </summary>
        private void FormList()
        {
            Last = new Carriage();

            Last.SetNumber(1);
            Count++;
        }

        /// <summary>
        /// Метод формує перший вагон із вказаним типом
        /// </summary>
        /// <param name="atype">Тип вагона</param>
        private void FormList(string atype)
        {
            Last = new Carriage(atype);

            Last.SetNumber(1);
            Count++;
        }
        #endregion
    }
}