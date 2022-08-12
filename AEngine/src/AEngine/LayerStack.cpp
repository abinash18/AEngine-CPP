#include "aepch.h"
#include "LayerStack.h"

namespace AEngine {
    LayerStack::LayerStack() {
    };

    LayerStack::~LayerStack() {
        for (Layer* layer : layers) {
            delete layer;
        }
    };

    // Remove the layer from the vector
    void LayerStack::popLayer(Layer* layer) {
        auto lyr = std::find(layers.begin(), layers.begin() + layerInsertIndex, layer);
        if (lyr != layers.end()) {
            layers.erase(lyr);
            layerInsertIndex--;
            layer->detach();
        }
    };

    void LayerStack::pushLayer(Layer* layer) {
        layers.emplace(layers.begin() + layerInsertIndex, layer);
        layer->attach();
        layerInsertIndex++;
    };

    void LayerStack::popOverlay(Layer* overlay) {
        auto ovr = std::find(layers.begin() + layerInsertIndex, layers.end(), overlay);
        if (ovr != layers.end()) {
            layers.erase(ovr);
            overlay->detach();
        }
    };

    void LayerStack::pushOverlay(Layer* overlay) {
        layers.emplace_back(overlay);
        overlay->attach();
    };

}
