#include "tests_common.hpp"
#include "caeserencryptor.hpp"
#include <array>

TEST( caeserencryptor, encrypt )
{
	constexpr kerberos::encryption::CaeserEncryptor enc{ 3 };
	constexpr std::array buffer{ 'a', 'c', 'd', 'g', 'f', static_cast< char >( 255 ) };

	constexpr auto encrypted = enc.encrypt( buffer );
	ASSERT_NE(buffer, encrypted);

	constexpr auto decrypted = enc.decrypt( encrypted );
	ASSERT_NE(encrypted, decrypted);
	ASSERT_EQ( buffer, decrypted );
}

TEST( caeserencryptor, encrypt_inplace)
{
	constexpr kerberos::encryption::CaeserEncryptor enc{ 3 };
	std::array buffer{ 'a', 'c', 'd', 'g', 'f', static_cast< char >( 255 ) };
	auto copy{buffer};
	ASSERT_EQ(buffer, copy);

	enc.encrypt_inplace(buffer);
	ASSERT_NE(buffer, copy);

	enc.decrypt_inplace(buffer);
	ASSERT_EQ(buffer, copy);
}