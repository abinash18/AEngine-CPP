#pragma once
#include <vector>
#include "Layer.h"
#include "AEngine/core/Core.h"

namespace AEngine {
    class AE_API LayerStack {
        public:
            LayerStack();
            ~LayerStack();

            // Change the names to addLayer/Overlay, removeLayer/Overlay.
            void pushLayer(Layer* layer);
            void popLayer(Layer* layer);
            void pushOverlay(Layer* layer);
            void popOverlay(Layer* overlay);

            std::vector<Layer*>::iterator begin() {
                return layers.begin();
            }

            std::vector<Layer*>::iterator end() {
                return layers.end();
            }

        private:
            std::vector<Layer*> layers;
            int                 layerInsertIndex = 0;
    };
}
