#include <AEngine.h>

class testLayer : public AEngine::Layer {
	public:
		testLayer() : Layer("test") { }

		void update() override {
			//AE_INFO("testLayer::update");
		}

		void onEvent(AEngine::Event& event) override {
			AE_TRACE("{0}", event);
			event.handled = true;
		}
};

class TestBox : public AEngine::Application {
	public:
		TestBox() {
			pushLayer(new testLayer());
		};

		~TestBox() override {};
};

AEngine::Application* AEngine::createApplication() {
	AE_INFO("Starting");
	return new TestBox();
}
