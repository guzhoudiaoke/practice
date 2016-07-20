/*
 * poj 3299:
 * 
 *  The humidex formula is as follows:
 *  humidex = temperature + h
 *  h = (0.5555)× (e - 10.0)
 *  e = 6.11 × exp [5417.7530 × ((1/273.16) - (1/(dewpoint+273.16)))]
 *  exp(x) is 2.718281828 raised to the exponent x. 是一个以自然数e 为底的指数函数
 *
 *  guzhoudiaoke@126.com
 *  2011-08-27
 */

#include <stdio.h>
#include <math.h>

float calc_h(float temperature, float dew)
{
	float e = 6.11 * exp(5417.7530 * ((1/273.16) - (1/(dew+273.16))));
	float h = (0.5555) * (e - 10.0);
	float humidex = temperature + h;
	
	return humidex;
}

float calc_t(float dew, float humidex)
{
	float e = 6.11 * exp(5417.7530 * ((1/273.16) - (1/(dew+273.16))));
	float h =(0.5555) * (e - 10.0);
	float temperature = humidex - h;
	
	return temperature;
}

float calc_d(float temperature, float humidex)
{
	float h = humidex - temperature;
	float e = h / 0.5555 + 10.0;
	float dew = 1 / (1/273.16 - log(e/6.11)/5417.7530) - 273.16;
	
	return dew;
}

int main()
{
	float temperature, dew, humidex;
	float h, e, f1, f2;
	char c1, c2;
	while(scanf("%c", &c1), c1 != 'E')
	{	
		scanf("%f %c %f",&f1, &c2, &f2);
		switch (c1+c2)
		{
		case 'T'+'D':
			{
				temperature = (c1=='T') ? f1:f2;
				dew = (c1=='D') ? f1:f2;
				humidex = calc_h(temperature, dew);
				break;
			}
		case 'T'+'H':
			{
				temperature = c1=='T' ? f1:f2;
				humidex = (c1=='H') ? f1:f2;
				dew = calc_d(temperature, humidex);
				break;
			}

		case 'H'+'D':
			{
				humidex = (c1=='H') ? f1:f2;
				dew = (c1=='D') ? f1:f2;
				temperature = calc_t(dew, humidex);
				break;
			}
		}
		printf("T %.1f D %.1f H %.1f\n", temperature, dew, humidex);
		scanf("%c", &c1);
	}
	
	return 0;
}
