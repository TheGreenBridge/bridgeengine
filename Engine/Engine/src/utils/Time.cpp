#include "Time.h"

Time::Time():
	m_Dt(0), m_PastTime(0){

}

void Time::measureTime() {
	std::chrono::high_resolution_clock::now();
	auto now = std::chrono::high_resolution_clock::now();
	// operation to be timed ...
	//std::cin.get();
	m_Dt = std::chrono::duration_cast<std::chrono::milliseconds>(now-m_LastTime).count();
	m_LastTime = now;
	//std::cout << "vergangene Zeit:" << time << "Seconds" << "ns\n";
	m_PastTime += m_Dt;
}

void Time::init() {
	m_Dt = 0;
	m_PastTime = 0;
}

void Time::start() {
	m_LastTime = std::chrono::high_resolution_clock::now();
}

void Time::erasePastTime() {
	m_PastTime = 0;
}

long long Time::getDelta() const {
	return m_Dt;
}


long long Time::getPastTime() const {
	return m_PastTime;
}