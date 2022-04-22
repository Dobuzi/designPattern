#include <unordered_map>
#include <iostream>
#include <vector>

class Graphics
{
	int penWidth = 1;
	int penColor = 0;
	int temporary_data;

	struct Memento
	{
		int penWidth;
		int penColor;

		Memento(int w, int c) : penWidth(w), penColor(c) {}
	};
	std::unordered_map<int, Memento*> m;

public:
	int Save()
	{
		static int key = 1;
		++key;
		m[key] = new Memento(penWidth, penColor);

		return key;
	}

	void Restore(int key)
	{
		Memento* p = m[key];

		penWidth = p->penWidth;
		penColor = p->penColor;
	}

	void DrawLine(int x1, int y1, int x2, int y2)
	{

	}
	void SetStrokeColor(int c) { penColor = c; }
	void SetStrokeWidth(int w) { penWidth = w; }
};

int main()
{
	Graphics g;

	g.SetStrokeColor(0);
	g.SetStrokeWidth(10);
	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 200, 200);

	int token = g.Save();

	g.SetStrokeColor(1);
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);

	g.Restore(token);
}









