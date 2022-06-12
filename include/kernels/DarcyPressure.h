#pragma once
#include "ADKernelGrad.h"

/* compute the residual contribution: K/mu *grad_test *grad_u*/
class DarcyPressure : public ADKernelGrad
{
public:
  static InputParameters validParams();

  DarcyPressure(const InputParameters & parameters);

protected:
  virtual ADRealVectorValue precomputeQpResidual() override;

  const Real _permeability;
  const Real _viscosity;
};