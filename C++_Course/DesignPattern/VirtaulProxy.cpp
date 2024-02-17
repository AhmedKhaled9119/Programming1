
#include <iostream>
// Step 1: Define the Subject interface
class Image {
public:
	virtual void display() = 0;
};

// Step 2: Implement the Real Object
class RealImage : public Image {
private:
	std::string filename;

public:
	RealImage(const std::string& filename) : filename(filename) {
		// Simulate loading the image (this can be a resource-intensive operation)
		std::cout << "Loading image: " << filename << std::endl;
	}

	void display() override {
		std::cout << "Displaying image: " << filename << std::endl;
	}
};

// Step 3: Create the Proxy
class ImageProxy : public Image {
private:
	RealImage* realImage; // Reference to the Real Object
	std::string filename;

public:
	ImageProxy(const std::string& filename) : filename(filename), realImage(nullptr) {}

	void display() override {
		// The Proxy checks if the Real Object is created and loads it if necessary
		if (realImage == nullptr) {
			realImage = new RealImage(filename);
		}
		realImage->display();
	}
};

int main() {
	// Create a proxy to an image
	Image* image = new ImageProxy("example.jpg");

	// Display the image (the Proxy will load the Real Object if necessary)
	image->display();

	// Displaying the image again (the Proxy won't reload it)
	// image->display();

	delete image; // Clean up

	return 0;
}

