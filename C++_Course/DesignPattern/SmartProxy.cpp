#include <iostream>
#include <string>
#include <unordered_map>

// Subject interface
class ImageLoader {
public:
    virtual void displayImage(const std::string& imageName) = 0;
    virtual ~ImageLoader() {}
};

// RealSubject
class RealImageLoader : public ImageLoader {
public:
    void displayImage(const std::string& imageName) override {
        std::cout << "Displaying image: " << imageName << std::endl;
        // Simulate loading and displaying the image
    }
};

// Smart Proxy with lazy initialization and caching
class SmartProxy : public ImageLoader {
private:
    RealImageLoader* realImageLoader;
    std::unordered_map<std::string, bool> cache;

public:
    SmartProxy() : realImageLoader(nullptr) {}

    ~SmartProxy() {
        delete realImageLoader;
    }

    void displayImage(const std::string& imageName) override {
        if (!realImageLoader) {
            realImageLoader = new RealImageLoader();
        }

        if (!cache[imageName]) {
            realImageLoader->displayImage(imageName);
            cache[imageName] = true;
        } else {
            std::cout << "Image '" << imageName << "' fetched from cache." << std::endl;
        }
    }
};

// Client
int main() {
    // Using Proxy with lazy initialization and caching
    SmartProxy proxy;
    proxy.displayImage("image1.jpg"); // Image loaded and displayed
    proxy.displayImage("image2.jpg"); // Image loaded and displayed
    proxy.displayImage("image1.jpg"); // Image fetched from cache
    proxy.displayImage("image3.jpg"); // Image loaded and displayed
    return 0;
}