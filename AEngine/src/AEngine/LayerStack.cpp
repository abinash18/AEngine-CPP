#include "aepch.h"
#include "LayerStack.h"

namespace AEngine {
	LayerStack::LayerStack() {
		layerIterator = layers.begin();
	};

	LayerStack::~LayerStack() {
		for (Layer* layer : layers) {
			delete layer;
		}
	};

	// Remove the layer from the vector
	void LayerStack::popLayer(Layer* layer) {
		auto lyr = std::find(layers.begin(), layers.end(), layer);

		if (lyr != layers.end()) {
			layers.erase(lyr);
			layerIterator--;
		}
	};

	void LayerStack::pushLayer(Layer* layer) {
		layerIterator = layers.emplace(layerIterator, layer);
	};

	void LayerStack::popOverlay(Layer* overlay) {
		auto ovr = std::find(layers.begin(), layers.end(), overlay);

		if (ovr != layers.end()) {
			layers.erase(ovr);
		}

	};

	void LayerStack::pushOverlay(Layer* overlay) {
		layers.emplace_back(overlay);
	};

}
