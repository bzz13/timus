using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Timus2073
{
	public class Contest
	{
		public Contest()
		{
			Name = Date = Result = string.Empty;
		}
		public string Name { get; private set; }
		public string Date { get; private set; }
		public string Result { get; private set; }


		public void ReadFrom(TextReader textReader)
		{
			Name = textReader.ReadLine();
			Date = textReader.ReadLine();
			var l = textReader.ReadLine().Split(new[] { ' ' }, 2).Select(str => str.Trim()).Select(Int32.Parse).ToArray();
			var p = l[0];
			var s = l[1];

			const string src = "ABCDEFGHIJKLM";
			var results = src.ToCharArray().ToDictionary(c => c.ToString(), c => src.IndexOf(c) < p ? "." : " ");
			for (int i = 0; i < s; i++)
			{
				var ll = textReader.ReadLine().Split(new[] { " " }, StringSplitOptions.RemoveEmptyEntries);
				var key = ll[0];
				var val = string.Join(" ", ll.Skip(1));
				results[key] = val.Equals("Accepted") || results[key].Equals("o") ? "o" : "x";
			}

			Result = string.Join("", results.Values);
		}

		public void WriteTo(TextWriter textWriter)
		{
			textWriter.WriteLine(ToString());
		}

		public override string ToString()
		{
			return string.Format(
@"|{0}|{1}|{2}|
+------------------------------+--------+-------------+",
				Name.PadRight(30, ' '),
				Date,
				Result.PadRight(13, ' '));
		}
	}

	static class Program
	{
		private const string Header =
@"+------------------------------+--------+-------------+
|Contest name                  |Date    |ABCDEFGHIJKLM|
+------------------------------+--------+-------------+";

		static void Main(string[] args)
		{
			var contests = new List<Contest>(2);
			var count = Int32.Parse(Console.In.ReadLine());

			for (var i = 0; i < count; i++)
			{
				var contest = new Contest();
				contest.ReadFrom(Console.In);
				contests.Add(contest);
			}


			Console.Out.WriteLine(Header);
			for (var i = 0; i < count; i++)
			{
				contests[i].WriteTo(Console.Out);
			}
		}
	}
}
