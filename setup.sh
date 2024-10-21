
# Set Up Python + Conan
python3 -m venv env
source ./env/bin/activate
pip install -r requirements.txt

# Install Libraries / Dependencies
mkdir build
conan install --build=missing -of=build .
