# Set Up Python + Conan
python3 -m venv env
source ./env/bin/activate
pip install -r requirements.txt

# Install Libraries / Dependencies
mkdir build
conan install --build=missing -if=conan -s ./conan/conanfile.py

# Sample
cp ~/.env.sample .env
echo "Created a raw .env file. Fill it with your local environment variables."
