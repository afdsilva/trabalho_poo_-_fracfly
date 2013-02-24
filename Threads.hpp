#ifndef THREAD_H
#define THREAD_H


#include <stdio.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <vector>

#include <pthread.h>

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

using namespace std;



#define NUM_THREADS 5


class Thread {
	private:
		pthread_t m_threadId;

	public:
		Thread();
		~Thread();

		void Start();
		void Wait();
		void Abort();
		void Detach();

		pthread_t GetId();

	protected:
		static void *entryPoint(void *pthis);
		virtual void run() = 0;


};

#endif
