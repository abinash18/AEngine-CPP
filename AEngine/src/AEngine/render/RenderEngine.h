#pragma once
namespace AEngine {

    enum class RenderAPI {
        NONE = 0,
        OPEN_GL = 1
        //VULKAN = 2
    };

    class RenderEngine {
        public:
            inline static RenderAPI getAPI() {
                return s_render_api;
            };

            RenderEngine() {
            };

            ~RenderEngine() {
            };
            virtual void init() = 0;
            virtual void render() = 0;
            virtual void update() = 0;

            /**
             * @brief This function prints system and API info retrieved from the initialized renderer.
            */
            virtual void printAPIInfo() = 0;
        private:
            static RenderAPI s_render_api;
    };
}
