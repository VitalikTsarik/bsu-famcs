using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace _08
{
    class Parallepiped :
        Body, IComparable, IComparer, IDisposable
    {
        private Vector3 OA { set; get; }
        private Vector3 OB { get; set; }
        private Vector3 OC { get; set; }

        public static string[] Names = { "Generating vectors", "Sum of edge lengths", "Volume", "Surface Area" };
        public enum eSortBy { Sum_of_edge_lengths = 1, Volume, SurfaceArea };
        private static eSortBy sortBy = eSortBy.Sum_of_edge_lengths;
        public static eSortBy SortBy
        {
            get { return sortBy; }
            set
            {
                if (value > eSortBy.SurfaceArea || value < 0)
                {
                    throw new IndexOutOfRangeException();
                }
                sortBy = value;
            }
        }
        
        private Parallepiped() { }

        public Parallepiped(Vector3 OA, Vector3 OB, Vector3 OC)
        {
            this.OA = OA;
            this.OB = OB;
            this.OC = OC;
        }
        public Parallepiped(float OA_x, float OA_y, float OA_z, float OB_x, float OB_y, float OB_z, float OC_x, float OC_y, float OC_z)
        {
            OA = new Vector3(OA_x, OA_y, OA_z);
            OB = new Vector3(OB_x, OB_y, OB_z);
            OC = new Vector3(OC_x, OC_y, OC_z);
        }
        public Parallepiped(string str) // example "<1, 1, 1>|<2, 2, 3>|<3, 3, 3>"
        {
            string[] tmp = str.Split('|', '<', '>', ',');
            OA = new Vector3(float.Parse(tmp[1]), float.Parse(tmp[2]),float.Parse(tmp[3]));
            OB = new Vector3(float.Parse(tmp[6]), float.Parse(tmp[7]), float.Parse(tmp[8]));
            OC = new Vector3(float.Parse(tmp[11]), float.Parse(tmp[12]), float.Parse(tmp[13]));
        }

        public string this[int idx]
        {
            get
            {
                if (idx >= Names.Length || idx < 0)
                {
                    throw new
                        IndexOutOfRangeException();
                }
                switch (idx)
                {
                    case 0:
                        return OA.ToString() + ", " + OB.ToString() + ", " + OC.ToString();
                    case 1:
                        return Sum_of_edge_lengths().ToString();
                    case 2:
                        return Volume().ToString();
                    case 3:
                        return SurfaceArea().ToString();
                    default:
                        return null;
                }
            }
        }

        public float Sum_of_edge_lengths()
        {
            return 4*(OA.Length() + OB.Length() + OC.Length());
        }
        public float SurfaceArea()
        {
            return Vector3.Cross(OA, OB).Length() * 2 + Vector3.Cross(OB, OC).Length() * 2 + Vector3.Cross(OC, OA).Length() * 2;
        }
        public float Volume() // Модуль смешанного произведения
        {
            return (Vector3.Dot(OA, Vector3.Cross(OB, OC)) > 0) ? Vector3.Dot(OA, Vector3.Cross(OB, OC)) : -Vector3.Dot(OA, Vector3.Cross(OB, OC));
        }

        public int Compare(object x, object y)
        {
            return ((Parallepiped)x).CompareTo(y);
        }

        public int CompareTo(object _obj)
        {
            Parallepiped obj = (Parallepiped)_obj;
            switch (sortBy)
            {
                case eSortBy.Sum_of_edge_lengths:
                        return (OA.Length() + OB.Length() + OC.Length()).CompareTo(obj.OA.Length() + obj.OB.Length() + obj.OC.Length());
                case eSortBy.SurfaceArea:
                    return SurfaceArea().CompareTo(obj.SurfaceArea());
                case eSortBy.Volume:
                    return Volume().CompareTo(obj.Volume());
            }
            throw new Exception();
        }

        public void Dispose()
        {
            Names = null;
            if (OA != null)
                OA = Vector3.Zero;
            if (OB != null)
                OB = Vector3.Zero;
            if (OC != null)
                OC = Vector3.Zero;
            
            GC.SuppressFinalize(this);
        }

        public override string ToString()
        {
            return OA.ToString() + '|' + OB.ToString() + '|' + OC.ToString();
        }
        
    }
}
