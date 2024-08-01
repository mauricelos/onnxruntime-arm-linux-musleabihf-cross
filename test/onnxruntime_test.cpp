#include <iostream>
#include <onnxruntime/core/session/onnxruntime_cxx_api.h>

int main()
{
    try
    {
        Ort::Env env(ORT_LOGGING_LEVEL_WARNING, "test");
        Ort::SessionOptions session_options;
        session_options.SetIntraOpNumThreads(1);

        std::cout << "ONNX Runtime environment initialized successfully!" << std::endl;

        auto memory_info = Ort::MemoryInfo::CreateCpu(OrtAllocatorType::OrtArenaAllocator, OrtMemType::OrtMemTypeDefault);
        
        std::cout << "Memory Info object for CPU created successfully!" << std::endl;

        std::vector<float> tensor_values = {1.0, 2.0, 3.0};
        std::vector<int64_t> tensor_shape = {3};
        
        Ort::Value tensor = Ort::Value::CreateTensor<float>(memory_info, tensor_values.data(), tensor_values.size(), tensor_shape.data(), tensor_shape.size());
        
        if (tensor.IsTensor())
        {
            std::cout << "Tensor created successfully!" << std::endl;
        } else
        {
            std::cout << "Tensor creation failed!" << std::endl;
        }

    } 
    catch (const Ort::Exception& e)
    {
        std::cerr << "ONNX Runtime exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
