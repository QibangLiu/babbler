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

  /// The material properties which hold the values for K and mu
  const ADMaterialProperty<Real> & _permeability;
  const ADMaterialProperty<Real> & _viscosity;
};