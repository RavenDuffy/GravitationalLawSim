#ifndef GAMERUN_H
#define GAMERUN_H

class GameRun {
	public:
		GameRun();
		void startGame();
	protected:

	private:
		void gameLoop();
		void fillPList(int pNum);
		void draw();
		void update();
		void updateParticles();
		void drawParticles();
};
#endif // !GAMERUN_H;
