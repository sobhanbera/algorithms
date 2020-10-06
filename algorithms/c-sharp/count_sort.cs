

 public class Solution
    {
        public IList<string> WordSubsets(string[] a, string[] b)
        {
            IList<string> res = new List<string>();

            int[,] bwMap = new int[b.Length,26];

            for (int i = 0; i < b.Length; i++)
            {
                var bw = b[i];
                for (int j = 0; j < bw.Length; j++)
                {
                    bwMap[i, bw[j] - 'a']++;
                }
            }

            int[] targetCounts = new int[26];
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < b.Length; j++)
                {
                    targetCounts[i] = Math.Max(targetCounts[i], bwMap[j, i]);
                }
            }


            foreach (var aw in a)
            {
                int[] curr = new int[26];
                foreach (var c in aw)
                {
                    curr[c - 'a']++;
                }

                bool valid = true;
                for (int i = 0; i < 26; i++)
                {
                    if (curr[i] < targetCounts[i])
                    {
                        valid = false;
                        break;
                    }
                }

                if (valid)
                {
                    res.Add(aw);
                }
            }

            return res;
        }
    }
