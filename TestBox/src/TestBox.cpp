#include <AEngine.h>

class TestBox : public AEngine::Application {
	public:
		TestBox() {};

		~TestBox() override {};
};

AEngine::Application* AEngine::createApplication() {
	AE_INFO("Starting");
	return new TestBox();
}
