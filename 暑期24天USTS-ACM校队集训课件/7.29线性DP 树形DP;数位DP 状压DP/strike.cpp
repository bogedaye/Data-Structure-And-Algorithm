#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>

#define debug(...) fprintf(stderr, __VA_ARGS__)

#ifndef AT_HOME
#define getchar() IO::myGetchar()
#define putchar(x) IO::myPutchar(x)
#endif

namespace IO {
	static const int IN_BUF = 1 << 23, OUT_BUF = 1 << 23;

	inline char myGetchar() {
		static char buf[IN_BUF], *ps = buf, *pt = buf;
		if (ps == pt) {
			ps = buf, pt = buf + fread(buf, 1, IN_BUF, stdin);
		}
		return ps == pt ? EOF : *ps++;
	}

	template<typename T>
	inline bool read(T &x) {
		bool op = 0;
		char ch = getchar();
		x = 0;
		for (; !isdigit(ch) && ch != EOF; ch = getchar()) {
			op ^= (ch == '-');
		}
		if (ch == EOF) {
			return false;
		}
		for (; isdigit(ch); ch = getchar()) {
			x = x * 10 + (ch ^ '0');
		}
		if (op) {
			x = -x;
		}
		return true;
	}

	inline int readStr(char *s) {
		int n = 0;
		char ch = getchar();
		for (; isspace(ch) && ch != EOF; ch = getchar())
			;
		for (; !isspace(ch) && ch != EOF; ch = getchar()) {
			s[n++] = ch;
		}
		s[n] = '\0';
		return n;
	}

	inline void myPutchar(char x) {
		static char pbuf[OUT_BUF], *pp = pbuf;
		struct _flusher {
			~_flusher() {
				fwrite(pbuf, 1, pp - pbuf, stdout);
			}
		};
		static _flusher outputFlusher;
		if (pp == pbuf + OUT_BUF) {
			fwrite(pbuf, 1, OUT_BUF, stdout);
			pp = pbuf;
		}
		*pp++ = x;
	}

	template<typename T>
	inline void print_(T x) {
		if (x == 0) {
			putchar('0');
			return;
		}
		std::vector<int> num;
		if (x < 0) {
			putchar('-');
			x = -x;
		}
		for (; x; x /= 10) {
			num.push_back(x % 10);
		}
		while (!num.empty()) {
			putchar(num.back() ^ '0');
			num.pop_back();
		}
	}

	template<typename T>
	inline void print(T x, char ch = '\n') {
		print_(x);
		putchar(ch);
	}

	inline void printStr_(const char *s, int n = -1) {
		if (n == -1) {
			n = strlen(s);
		}
		for (int i = 0; i < n; ++i) {
			putchar(s[i]);
		}
	}

	inline void printStr(const char *s, int n = -1, char ch = '\n') {
		printStr_(s, n);
		putchar(ch);
	}
}
using namespace IO;

const int N = 5005, P = 1000000007;

int n, type, D;
std::vector<int> E[N];
int fa[N];

std::pair<int, int> dfs(int u, int fa = 0) {
	std::pair<int, int> res(0, u);
	for (int v : E[u]) {
		if (v != fa) {
			std::pair<int, int> tmp = dfs(v, u);
			++tmp.first;
			res = std::max(res, tmp);
		}
	}
	return res;
}

void getfa(int u) {
	for (int v : E[u]) {
		if (v != fa[u]) {
			fa[v] = u, getfa(v);
		}
	}
}

int f[N][N << 1];

void DP(int u, int fa, int d) {
	for (int i = -D; i <= D; ++i) {
		f[u][i + D] = -d <= i && i <= d;
	}
	for (int v : E[u]) {
		if (v != fa) {
			DP(v, u, d - 1);
			for (int i = 0; i <= 2 * D; ++i) {
				f[u][i] = 1ll * f[u][i] * ((i == 0 ? 0 : f[v][i - 1]) + (i == 2 * D ? 0 : f[v][i + 1])) % P;
			}
		}
	}
}

int main() {
	read(n), read(type);
	for (int i = 1; i < n; ++i) {
		int u, v;
		read(u), read(v);
		E[u].push_back(v), E[v].push_back(u);
	}
	int S = dfs(1).second, T;
	std::pair<int, int> tmp = dfs(S);
	T = tmp.second;
	D = tmp.first;
	getfa(S);
	if (D & 1) {
		D = (D + 1) >> 1;
		print(D);
		int s, t = T, ans = 0;
		for (int i = 1; i < D; ++i) {
			t = fa[t];
		}
		s = fa[t];
		DP(s, t, D), DP(t, s, D - 1);
		for (int i = 0; i <= 2 * D; ++i) {
			ans = (ans + 1ll * f[s][i] * f[t][i + 1]) % P;
			ans = (ans + 1ll * f[t][i] * f[s][i + 1]) % P;
		}
		DP(s, t, D - 1), DP(t, s, D);
		for (int i = 0; i <= 2 * D; ++i) {
			ans = (ans + 1ll * f[s][i] * f[t][i + 1]) % P;
			ans = (ans + 1ll * f[t][i] * f[s][i + 1]) % P;
		}
		DP(s, t, D - 1), DP(t, s, D - 1);
		for (int i = 0; i <= 2 * D; ++i) {
			ans = (ans - 2ll * f[s][i] * f[t][i]) % P;
			ans = (ans - 1ll * f[s][i] * f[t][i + 2]) % P;
			ans = (ans - 1ll * f[t][i] * f[s][i + 2]) % P;
		}
		print((ans + P) % P);
	} else {
		D >>= 1;
		print(D);
		int r = T, ans = 0;
		for (int i = 1; i <= D; ++i) {
			r = fa[r];
		}
		DP(r, 0, D);
		for (int i = 0; i <= 2 * D; ++i) {
			ans = (ans + f[r][i]) % P;
		}
		print(ans);
	}
}
