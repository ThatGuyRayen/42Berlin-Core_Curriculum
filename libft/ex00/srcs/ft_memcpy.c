void	memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*dest;
	const unsigned char	*source;
	size_t	i;

	i = 0;
	dest = (unsigned char *)dst;
	source = (const unsigned char *)src;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}
