#pragma once
#include <string>
#include <SDL.h>
using namespace std;

class Window {
public:
	Window(const string& title, int width, int height);
	~Window();

private:
	string _title;
	int _width = 800;
	int _height = 600;
	bool _closed = false;

	SDL_Window* _window = nullptr;
protected:
	SDL_Renderer* _renderer = nullptr;

private:
	bool init();

public:

	inline bool isClosed() { return _closed; }
	void pollEvents(SDL_Event& event);
	void clear() const;
};