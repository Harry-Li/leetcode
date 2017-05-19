	int romanToInt(string s) {
		int len = s.length();
		int i = 0, num = 0;
		if (s.find("MMM") != s.npos) num += 3000, i += 3;
		else if (s.find("MM") != s.npos) num += 2000, i += 2;
		else if (s[0] == 'M') num += 1000, ++i;

		if (i == len) return num;
		else if (s.find("CM") != s.npos) num += 900, i += 2;
		else if (s.find("DCCC") != s.npos) num += 800, i += 4;
		else if (s.find("DCC") != s.npos) num += 700, i += 3;
		else if (s.find("DC") != s.npos) num += 600, i += 2;
		else if (s.find("CD") != s.npos) num += 400, i += 2;
		else if (s.find("D") != s.npos) num += 500, ++i;
		else if (s.find("CCC") != s.npos) num += 300, i += 3;
		else if (s.find("CC") != s.npos) num += 200, i += 2;
		else if (s[i] == 'C') num += 100, ++i;

		if (i == len) return num;
		else if (s.find("XC") != s.npos) num += 90, i += 2;
		else if (s.find("LXXX") != s.npos) num += 80, i += 4;
		else if (s.find("LXX") != s.npos) num += 70, i += 3;
		else if (s.find("LX") != s.npos) num += 60, i += 2;
		else if (s.find("XL") != s.npos) num += 40, i += 2;
		else if (s.find("L") != s.npos) num += 50, ++i;
		else if (s.find("XXX") != s.npos) num += 30, i += 3;
		else if (s.find("XX") != s.npos) num += 20, i += 2;
		else if (s[i] == 'X') num += 10, ++i;

		if (i == len) return num;
		else if (s.find("IX") != s.npos) num += 9, i += 2;
		else if (s.find("VIII") != s.npos) num += 8, i += 4;
		else if (s.find("VII") != s.npos) num += 7, i += 3;
		else if (s.find("VI") != s.npos) num += 6, i += 2;
		else if (s.find("IV") != s.npos) num += 4, i += 2;
		else if (s.find("V") != s.npos) num += 5, ++i;
		else if (s.find("III") != s.npos) num += 3, i += 3;
		else if (s.find("II") != s.npos) num += 2, i += 2;
		else if (s[i] == 'I') num += 1, ++i;

		return num;
	}
