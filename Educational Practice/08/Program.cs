using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;

namespace _08
{
    class Program
    {
        static void SortAndPrint(ArrayList pl)
        // simple printout
        {

            Console.WriteLine("----- Sorted by: {0}", Parallepiped.Names[(int)Parallepiped.SortBy]);
            pl.Sort((Parallepiped)pl[0]);
            foreach (Parallepiped p in pl)
            {
                for (int i = 0; i < Parallepiped.Names.Length; i++)
                {
                    string str = p[i];
                    if (str.Length > 0)
                    {
                        Console.Write("{0}: {1} ", Parallepiped.Names[i], str);
                    }
                }
                Console.WriteLine();
            }
        }

        static void Main(string[] args)
        {
            ArrayList arr = new ArrayList(3);
            Parallepiped p1 = new Parallepiped(-1, 0, 0, 0, -2, 0, 0, 0, -3);
            Parallepiped p2 = new Parallepiped(new Vector3(1, 2, 3), new Vector3(2, 3, 1), new Vector3(3, 1, 2));
            arr.Add(p1);
            arr.Add(p2);
            arr.Add(new Parallepiped("<1, 0, 0>|<0, 1, 0>|<0, 0, 1>"));

            Parallepiped.SortBy = Parallepiped.eSortBy.Sum_of_edge_lengths;
            SortAndPrint(arr);
            Parallepiped.SortBy = Parallepiped.eSortBy.SurfaceArea;
            SortAndPrint(arr);
            Parallepiped.SortBy = Parallepiped.eSortBy.Volume;
            SortAndPrint(arr);
        }
    }
}
